#include "Character3D.hpp"

std::vector<Character3D::RenderData> Character3D::_buffer;

ShadingProgram *Character3D::_program = nullptr;
bool	Character3D::_init;

std::vector<float> Character3D::_square;
std::vector<float> Character3D::_uv;

GLuint Character3D::_squareID;
GLuint Character3D::_UVID;
GLuint Character3D::_textureID;
GLuint Character3D::_textureLocationID;
GLuint Character3D::_projectionID;
GLuint Character3D::_lookAtID;
GLuint Character3D::_positionID;
GLuint Character3D::_sizeID;
GLuint Character3D::_colorID;

Character3D::Character3D(void)
{
	if (_init)
		return;

	_program = new ShadingProgram(CHAR3D_VERTEX_SHADER_PATH, "",
				      CHAR3D_FRAG_SHADER_PATH);

	_square.resize(18);
	_uv.resize(12);

	glm::vec2 topleft(-0.5, 0.5);
	glm::vec2 botright(0.5, -0.5);
	
	_square[0] = topleft.x; _square[1] = topleft.y; _square[2] = 0;
	_square[3] = topleft.x; _square[4] = botright.y; _square[5] = 0;
	_square[6] = botright.x; _square[7] = botright.y; _square[8] = 0;

	_square[9] = topleft.x; _square[10] = topleft.y; _square[11] = 0;
	_square[12] = botright.x; _square[13] = topleft.y; _square[14] = 0;
	_square[15] = botright.x; _square[16] = botright.y; _square[17] = 0;
	
	_textureLocationID = glGetUniformLocation(_program->ID(), "tex");
	_projectionID = glGetUniformLocation(_program->ID(), "projection");
	_lookAtID = glGetUniformLocation(_program->ID(), "lookAt");
	_positionID = glGetUniformLocation(_program->ID(), "position");
	_sizeID = glGetUniformLocation(_program->ID(), "size");
	_colorID = glGetUniformLocation(_program->ID(), "color");

	glUseProgram(_program->ID());
	
	glGenBuffers(1, &_squareID);
	glBindBuffer(GL_ARRAY_BUFFER, _squareID);
	glBufferData(GL_ARRAY_BUFFER,
		     2 * 9 * sizeof(GLfloat),
		     &_square[0],
		     GL_STATIC_DRAW);

	glGenBuffers(1, &_UVID);
	glBindBuffer(GL_ARRAY_BUFFER, _UVID);
	glBufferData(GL_ARRAY_BUFFER,
		     2 * 6 * sizeof(GLfloat),
		     NULL,
		     GL_STREAM_DRAW);

	Texture textureParser(FONT_FILE);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glGenTextures(1, &_textureID);
	glBindTexture(GL_TEXTURE_2D, _textureID);
	glTexImage2D(GL_TEXTURE_2D,
		     0,
		     GL_RGBA,
		     textureParser.Width(),
		     textureParser.Height(),
		     0,
		     GL_RGBA,
		     GL_UNSIGNED_BYTE,
		     textureParser.Data());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glGenerateMipmap(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(_textureLocationID, 0);

	_init = true;
}

void	Character3D::RenderAndClearBuffer(std::pair<glm::mat4, glm::mat4> perspective)
{
	auto comparison = [&perspective](RenderData& lhs, RenderData& rhs)
	{
		glm::vec4 p = perspective.first * glm::vec4(lhs.position, 1);
		glm::vec4 q = perspective.first * glm::vec4(rhs.position, 1);

		return p.z < q.z;
	};
	std::sort(_buffer.begin(), _buffer.end(), comparison);
	for (auto data : _buffer)
	{
		Character3D c;
		c.Render(perspective, data.position, data.color, data.size, data.c);
	}
	_buffer.resize(0);

}

void	Character3D::AddToBuffer(glm::vec3 position,
		    glm::vec3 color,
		    float size,
		    char c)
{
	_buffer.push_back(RenderData{position, color, size, c});
}

void	Character3D::Render(std::pair<glm::mat4, glm::mat4> perspective,
			    glm::vec3 position,
			    glm::vec3 color,
			    float size,
			    char c)
{
	glUseProgram(_program->ID());

	glUniformMatrix4fv(_projectionID,
			   1,
			   GL_FALSE,
			   glm::value_ptr(perspective.second));
	glUniformMatrix4fv(_lookAtID,
			   1,
			   GL_FALSE,
			   glm::value_ptr(perspective.first));
	glUniform3fv(_positionID, 1, &position.x);
	glUniform3fv(_colorID, 1, &color.x);
	glUniform1f(_sizeID, size);

	glm::vec2 topleftUV((c % 16) / 16.0f, (16 - (c / 16)) / 16.0f);
	glm::vec2 botrightUV(topleftUV.x + 1 / 16.0f, topleftUV.y - 1 / 16.0f);

	_uv[0] = topleftUV.x; _uv[1] = topleftUV.y;
	_uv[2] = topleftUV.x; _uv[3] = botrightUV.y;
	_uv[4] = botrightUV.x; _uv[5] = botrightUV.y;

	_uv[6] = topleftUV.x; _uv[7] = topleftUV.y;
	_uv[8] = botrightUV.x; _uv[9] = topleftUV.y;
	_uv[10] = botrightUV.x; _uv[11] = botrightUV.y;

	glBindTexture(GL_TEXTURE_2D, _textureID);
	glActiveTexture(GL_TEXTURE0);
	
	glBindBuffer(GL_ARRAY_BUFFER, _squareID);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindBuffer(GL_ARRAY_BUFFER, _UVID);
	glBufferData(GL_ARRAY_BUFFER,
		     12 * sizeof(GLfloat),
		     NULL,
		     GL_STREAM_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER,
			0,
			12 * sizeof(GLfloat),
			&_uv[0]);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	glDisable(GL_BLEND);
	
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
