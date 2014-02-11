engine.o: engine.cc EasyImage.h ini_configuration.hh opdrachten/o1.cpp \
 opdrachten/../EasyImage.h opdrachten/o2.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
