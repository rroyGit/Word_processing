#include <iostream>
#include "Story.h"


//using namespace std;

int main() {

  	/*
	Word hello("hello");
  	Word bye("bye");
  	Word cs240("cStwoforty");
	Word gg("gG");
	*/
	Word like("like");
	Word thiss("this");
	
	
	Story file("input.txt");
	//file.show();
	//file.save("output.txt");
	//file.show();
	//Story f = file + file;

	cout << "-----------------------------START---------------------------" << endl;
	//f.show();
	//cout << file.rest();
	
	//Sentence r("Like this like.");
		
	
	Paragraph gg("Hello World to CStwoforty! The robot exclaimed. It was excited to receive a new incoming class of students to teach for the semester.		");
	
	Story p = file + gg;
	//cout << p;
	
	
	//gg.show();
	
	
	//cout << --f;
	/*
	hello++;
	hello.show();
	
	hello--;
	hello.show();
	
	hello + 1;
	hello.show();
	
	bye = hello;
	bye.show();
	
	++hello;
	hello.show();

	*/
	cout << "----------------------------Sentence-------------------------" << endl;
	
	//Sentence a = like + (thiss + like);
	//cout << a;
	//a.rest().show();
	///a++.show();
	//a.show();
	
	//Sentence b = bye + (cs240 + hello);
	//b.show();
	
	
	//Sentence c = a + bye;
	//c.show();
	
	//Sentence d = hello + (bye + cs240);
	//d.show();
	
	//Sentence e = bye + d;
	//e.show();
	
	cout << "---------------------------Paragraph-------------------------" << endl;
	//Paragraph x = (like + thiss) + (like + like);
	//x.show();
	//Story s =  x + file;
	//s.show();
	
	//x + 1;
	//cout << x ;
	//cout << ++x;
	//cout << --x;
	//x.show();
	//++x;
	//x.show();
	//x = x + x;
	//x.first().show();
	//x++.show();
	//x + 1;
	//x.show();
	
	//std::cout << x.rest();
	//x.show();

	//Paragraph z = x + a;
	//z--.show();
	//z.show();
	
	//sen + para
	//Paragraph y = a + x;
	
	//Paragraph q = x + ((bye + hello) + (hello + cs240)); //head is null in paragraph copy constructor
	
	
	
	
	cout << "------------------------------Show---------------------------" << endl;
	//y.show();
	//q.show();
	
	//std::cout << z.first();
	//std::cout << z.rest();
	//std::cout << x.rest();  
	//z.show();
	//b--;
	//b.show();
	//b+1;
	//b.show();
	
	//std::cout << b;
	
	//std::cout << b.first();
	
	//std::cout << d.first();
	
	//std::cout << e.rest();
	
	//std::cout << d.rest();
	
	//bye = hello;
	//bye.show();
	
/*
{
    // test Word + Word
    std::cout << (hello + bye) << std::endl;
    // test Word + Sentence
    std::cout << (hello + (bye + cs240)) << std::endl;
    // test Sentence + Word
    std::cout << ((hello + bye) + cs240) << std::endl;
  }
   {
    // test Sentence + Sentence
    Paragraph p((hello + cs240) + (bye + cs240));
    std::cout << p << std::endl;
    // test Sentence + Paragraph
     std::cout << (hello + hello) + p << std::endl;
    // test Paragraph + Sentence
     std::cout << p + (bye + bye) << std::endl;
    // test Paragraph + Paragraph
     std::cout << p + p << std::endl;
  }
   //works

 {
    Story s("input.txt");
     Paragraph p((hello + cs240) + (bye + cs240));
    // test Paragraph + Story
     std::cout << p + s << std::endl;
    // test Story + Paragraph
     std::cout << s + p << std::endl;
    // test Story + Story
     std::cout << s + s << std::endl;
  }
 //works
{
    // test postfix ++/--
    std::cout << hello << std::endl;
     hello++;
    std::cout << hello << std::endl;
      hello--;
      std::cout << hello << std::endl;
      Sentence s(hello + cs240);
      s++;
      std::cout << s << std::endl;
      s--;
      std::cout << s << std::endl;
      Paragraph p(s + (bye + cs240));
      p++;
       std::cout << p << std::endl;
      p--;
       std::cout << p << std::endl;
      Story story("input.txt");
      story++;
     std::cout << story << std::endl;
      story--;
      std::cout << story << std::endl;
  }
//works

 {
    // test operator=
    Word word("what");
      word = hello;
       std::cout << word << std::endl;
      Sentence s(bye + cs240);
      s = (hello + cs240);
      std::cout << s << std::endl;
      Paragraph p("It was a rainy day. Everyone stayed inside.");
      p = s + (cs240 + Word("rocks"));
      std::cout << p << std::endl;
      Story story("input.txt");
      story = story + p;
      std::cout << story << std::endl;
  }

 //works upto here
{
    // test operator+(int)
    Word word("testing");
       std::cout << word + 1231 << std::endl;
       std::cout << word + 1 << std::endl;
       Sentence s(hello + cs240);
       s--;
      std::cout << s + 1231 << std::endl;
      std::cout << s + 1 << std::endl;
      Paragraph p("it was a rainy day. everyone stayed inside.");
      std::cout << p + 1231 << std::endl;
      std::cout << p + 1 << std::endl;
      Story story("input.txt");
     story--;
     std::cout << story + 1231 << std::endl;
     std::cout << story + 1 << std::endl;
  }
//works up to here now
 {
    // test prefix ++/--
    Word w1("Like");
     std::cout << w1 << "->";
     std::cout << ++w1 << std::endl;
     Word w2("likE");
     std::cout << w2 << "->";
     std::cout << ++w2 << std::endl;
     Word w3("LikE");
     std::cout << w3 << "->";
      std::cout << ++w3 << std::endl;
     Word w4("lIKe");
     std::cout << w4 << "->";
      std::cout << ++w4 << std::endl;
      Word w5("this");
     std::cout << w5 << "->";
      std::cout << ++w5 << std::endl;
      Word w6("TRASH");
      std::cout << w6 << "->";
      std::cout << ++w6 << std::endl;
      Word w7("omelet");
      std::cout << w7 << "->";
      std::cout << ++w7 << std::endl;
      Word w8("APPLE");
       std::cout << w8 << "->";
      std::cout << ++w8 << std::endl;
      Sentence s1("In autumn apples are incredibly awesome.");
     std::cout << ++s1 << "->";
     std::cout << --s1 << std::endl;
      Sentence s2("Like this.");
      std::cout << ++s2 << "->";
     std::cout << --s2 << std::endl;
      std::cout << ++(s1+s2) << std::endl;
      Story story("input.txt");
     std::cout << std::endl << std::endl << ++story + (s1+s2) << std::endl;
     std::cout << std::endl << std::endl << --(story + (s1+s2)) << std::endl;
  }
 //works upto here
 {
    // test first/rest
    Sentence s1("In autumn apples are incredibly awesome.");
      std::cout << s1.first() << std::endl;
      std::cout << s1.rest() << std::endl;
     Paragraph p1((hello+cs240) + s1);
      std::cout << p1.first() << std::endl;
     std::cout << p1.rest() << std::endl;
     Story story("input.txt");
     std::cout << story.first() << std::endl;
     std::cout << p1 + story.rest() << std::endl;
  }
 //works upto here
  {
    // test story.save
    Story story("input.txt");
      ++story;
      story--;
     Word good("good");
     Word morning("morning");
     Word night("night");
     Paragraph intro((good + morning) + (hello + cs240));
     Paragraph outro((good + night) + (bye + cs240));
     intro++;
     outro = outro + 1;
     story = intro + story + outro;
     story.save("output.txt");
  }
  //works
  */
	return 0;
}
