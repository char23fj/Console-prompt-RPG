fpGame: fpMain.o game.o item.o mainchar.o space.o fronthall.o workarea.o supplyroom.o office.o protochamber.o terminalroom.o
	g++ -g -std=c++11 fpMain.o game.o item.o mainchar.o space.o fronthall.o workarea.o supplyroom.o office.o protochamber.o terminalroom.o -o fpGame

fpMain.o: fpMain.cpp
	g++ -c -g -std=c++11 fpMain.cpp

game.o: game.cpp game.hpp
	g++ -c -g -std=c++11 game.cpp

item.o: item.cpp item.hpp
	g++ -c -g -std=c++11 item.cpp

mainchar.o: mainchar.cpp mainchar.hpp
	g++ -c -g -std=c++11 mainchar.cpp

space.o: space.cpp space.hpp
	g++ -c -g -std=c++11 space.cpp

fronthall.o: fronthall.cpp fronthall.hpp
	g++ -c -g -std=c++11 fronthall.cpp

workarea.o: workarea.cpp workarea.hpp
	g++ -c -g -std=c++11 workarea.cpp

supplyroom.o: supplyroom.cpp supplyroom.hpp
	g++ -c -g -std=c++11 supplyroom.cpp

office.o: office.cpp office.hpp
	g++ -c -g -std=c++11 office.cpp

protochamber.o: protochamber.cpp protochamber.hpp
	g++ -c -g -std=c++11 protochamber.cpp

terminalroom.o: terminalroom.cpp terminalroom.hpp
	g++ -c -g -std=c++11 terminalroom.cpp



clean:
	rm *.o fpGame
