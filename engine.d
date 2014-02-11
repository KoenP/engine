engine.o: engine.cc EasyImage.h ini_configuration.hh
	$(CC) $(CXXFLAGS) -c $< -o $@
