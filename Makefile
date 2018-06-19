all:
	make -C server
	cd gfx && sh deps.sh && make

clean:
	@$(MAKE) -C server clean
	@$(MAKE) -C gfx clean

fclean: clean
	@$(MAKE) -C server fclean
	@$(MAKE) -C gfx fclean

re: fclean all
