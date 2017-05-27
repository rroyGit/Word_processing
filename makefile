#
#Target
all: driver

driver: Paragraph.o Sentence.o Story.o Word.o driver.o
	g++ Paragraph.o Sentence.o Story.o Word.o driver.o -o driver

driver.o: driver.cpp
	g++ -c driver.cpp
	
Paragraph.o: Paragraph.cpp
	g++ -c Paragraph.cpp
	
Sentence.o: Sentence.cpp
	g++ -c Sentence.cpp
	
Story.o: Story.cpp
	g++ -c Story.cpp
	
Word.o: Word.cpp
	g++ -c Word.cpp

clean:
	rm -f *.o driver
