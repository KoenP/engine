engine.o: engine.cc EasyImage.h ini_configuration.hh opdrachten/o1.cpp \
 opdrachten/../EasyImage.h
	$(CC) $(CXXFLAGS) -c $< -o $@
