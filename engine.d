engine.o: engine.cc EasyImage.h ini_configuration.hh opdrachten/o1.cpp \
 opdrachten/../EasyImage.h opdrachten/o2.cpp opdrachten/o3.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@
