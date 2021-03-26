tagger : driver.cpp tagger.cpp taggerhead.h
	g++ driver.cpp tagger.cpp taggerhead.h -o tagger

clean:
	rm -f tagger