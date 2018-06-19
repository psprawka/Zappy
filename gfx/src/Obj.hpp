#pragma once

#include "zappy.hpp"
#include "ShadingProgram.hpp"
#include "Texture.hpp"
#include "Light.hpp"
#include "ObjFileArrayExtractor.hpp"

#define STANDARD_OBJ_VERTEX "src/shaders/StandardObjVertex.glsl"
#define OUTLINE_OBJ_VERTEX "src/shaders/OutlineObjVertex.glsl"
#define STANDARD_OBJ_FRAG "src/shaders/StandardObjFrag.glsl"
#define CARTOON_OBJ_FRAG "src/shaders/CartoonObjFrag.glsl"
#define OUTLINE_OBJ_FRAG "src/shaders/OutlineObjFrag.glsl"

class	Obj
{
	static ShadingProgram *_normalProgram;
	static ShadingProgram *_outlineProgram;
	static ShadingProgram *_cartoonProgram;
	static bool _init;
	
	ObjFileArrayExtractor _extractor;
	Texture _textureParser;
	
	GLuint _uvArrayID;
	GLuint _normalArrayID;
	GLuint _vertexArrayID;
	
	static	GLuint _projectionID_normal;
	static	GLuint _lookAtID_normal;
	static	GLuint _transformID_normal;
	static	GLuint _textureLocationID_normal;
	static	GLuint _lightPosID_normal;
	static	GLuint _lightColorID_normal;
	static	GLuint _lightFalloffID_normal;
	static	GLuint _lightNumID_normal;
	static	GLuint _materialID_normal;
	
	
	static	GLuint _projectionID_cartoon;
	static	GLuint _lookAtID_cartoon;
	static	GLuint _transformID_cartoon;
	static	GLuint _textureLocationID_cartoon;
	static	GLuint _lightPosID_cartoon;
	static	GLuint _lightColorID_cartoon;
	static	GLuint _lightFalloffID_cartoon;
	static	GLuint _lightNumID_cartoon;
	static	GLuint _materialID_cartoon;

	static	GLuint _projectionID_outline;
	static	GLuint _transformID_outline;
	static	GLuint _colorID_outline;
	static	GLuint _sizeID_outline;
	
	GLuint _textureID;

	float _material[6];
	
	void	renderBackface(std::pair<glm::mat4, glm::mat4> perspective,
			       glm::mat4 transform,
			       glm::vec3 color,
			       float size);
	
public:

	static const glm::vec3 noOutline;
	static const std::vector<glm::vec3> noOutlines;
	static const std::vector<float> noSize;
	
	Obj(std::string filepath,
	    std::string texturePath,
	    float specular = 0,
	    float diffuse = 1,
	    float fog = 1000000,
	    glm::vec3 fogcol = glm::vec3(0));
	~Obj(void);

	void	Render(std::pair<glm::mat4, glm::mat4> perspective,
		       glm::mat4 transform,
		       glm::vec3 outlineColor = noOutline,
		       float outlineSize = 0.1,
		       bool cartoon = false);
/*	
	void	RenderInstanced(std::pair<glm::mat4, glm::mat4> perspective,
				std::vector<glm::mat4> transforms,
				std::vector<glm::vec3> outlineColors = noOutlines,
				std::vector<float> outlineSize = noSize);
*/
};
