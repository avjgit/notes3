#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
///////////////////////////////////////////////////////////////////
// "test" - paligfunkcija testa rezultatu parbaudei un izvadei
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
void test
(
     string description, // testa apraksts
     string expected,    // testa velamais rezultats
     string actual       // testa realais rezultats
)
{
     if (expected == actual)      // parbaudam, vai realais sakrit ar velamo
         cout << "test passed; "; // ja sakrit - tad tests veiksmigi nokartots
     else
         cout << "test FAILED! "; // ja nesakrit - tad testu "neizgajam"

     // te vienkarsi izvada rezultatu lietotajam draudziga forma
     cout << "tested "      << description
          << ": expected: " << expected
          << ", received: " << actual << endl;
}
// tas pats tests, tikai INT tipa rezultatiem
// abi TEST var saukties vienadi; kompilators pats sapratis, ko saukt
// (ir gana gudrs, lai tos atskirtu pec ieejas parametru tipiem - signaturas)
void test
(
     string description, 
     double expected,    
     double actual       
)
{
     if (expected == actual)      // parbaudam, vai realais sakrit ar velamo
         cout << "test passed; "; // ja sakrit - tad tests veiksmigi nokartots
     else
         cout << "test FAILED! "; // ja nesakrit - tad testu "neizgajam"

     // te vienkarsi izvada rezultatu lietotajam draudziga forma
     cout << "tested "      << description
          << ": expected: " << expected
          << ", received: " << actual << endl;
}
///////////////////////////////////////////////////////////////////
// laboratorijas darbu uzdevumi ar testiem
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
// funkcijas nosaukumu formats: "lab_", laboratorijas darba nr, uzdevuma nr, apraksts
string lab_01_1_hello ()
{
    return "Hello, world!";    
    return "Cau!";    
}
// katram uzdevumam ir tests
void lab_01_1_hello_test ()
{
     string expected = "Hello, world!";        // definejam velamo rezultatu (ko gribam no funkcijas sanemt?)
     string actual = lab_01_1_hello();         // pierakstam realo rezultatu (ko isteniba esam sanemusi)
     test("lab_01_1_hello", expected, actual); // padodam to visu funkcijai, kas prot to apstradat
                                               // un lai vina pasaka mums rezultatu
}
int lab_01_2_add (int x, int y)
{
    int z;
    z = x + y;
    return z;
//    return 42;
}
void lab_01_2_add_test ()
{
    int x, y;
    /*
    cout << "Input 2 integer values:" << endl;       // jautajam ieejas parametrus
    cin >> x >> y;                                   // un saglabajam
    test("lab_01_2_add 1", x + y, lab_01_2_add(x, y)); // lab_01_2_add rezultatu var nesaglabat, bet padot uzreiz
*/
    // varam ari nejautat, bet pasi pieskirt vertibas
    x = -1; 
    y = 1;
    test("lab_01_2_add 2", x + y, lab_01_2_add(x, y)); 

    // varam dod skaitlus "pa taisno", nelietojot mainigos
    test("lab_01_2_add 3", 123+456, lab_01_2_add(123, 456)); 
}
string lab_02_1_escapes()
{
//    return "HELLO\\,\n \"WORLD!\"";
      return "hello, world!";
}
void lab_02_1_escapes_test()
{
    test("lab_02_1_escapes", "HELLO\\,\n \"WORLD!\"", lab_02_1_escapes()); 
}
//float lab_02_2_types()
int lab_02_2_types()
{
//    float x, y, z;
    int x, y, z;
    x = 12;
    y = 7;
    z = x / y;
    return z;
}
void lab_02_2_types_test()
{
    test("lab_02_2_types", 12.0/7, lab_02_2_types());
}
float lab_02_3_format(
      string message, 
      bool clean= false, 
      int symbols= 256)
{
    cout << message << endl;
    double d = 987;
    cout << "Input numeric value #1" << endl;
	cin >> d;
    cout << "Output: " << d << endl;
    
    if (clean && !cin.good())
    {
        cin.clear();
        cin.ignore(symbols, '\n');
    }
    
    
    cout << "Input numeric value #2" << endl;
	cin >> d;
    cout << "Output: " << d << endl;
    return d;
}
void lab_02_3_format_test()
{
     float output;

     output = lab_02_3_format("Ievadiet skaitlus - 1.23, tad (nospiezot <Enter>) 4.56");
     test("lab_02_3_format normal", 4.56, output);

     output = lab_02_3_format("Tagad ievadiet tos pasus skaitlus viena reize, at atstarpi (un tad nospiediet <Enter>");
     test("lab_02_3_format spaced", 4.56, output);
     
     output = lab_02_3_format("Tagad ievadiet burtu");
     test("lab_02_3_format char", 987, output);

     output = lab_02_3_format("Tagad ievadiet burtu, <Enter>, pec tam ciparu 123", true);
     test("lab_02_3_format char fixed", 123, output);

     output = lab_02_3_format("Tagad ievadiet a123, <Enter>, tad ciparu 123", true);
     test("lab_02_3_format alphanumeric", 123, output);

     output = lab_02_3_format("Un tagad velreiz ievadiet a123 (un <Enter>)", true, 1);
     test("lab_02_3_format alphanumeric", 123, output);
     
}
double lab_02_4_format()
{ 
     double d;
     cout << endl << "Ievadiet skaitli 123.456789: ";
//     cin >> d;
     d = 123.456789;
     cout << endl << "Tads ir cout double tipa standarta izvades formats: ";
     cout << endl << d;
     cout << endl;
     cout << endl << "Redzam tikai 3 zimes aiz komata, ka ari - skaitlis tika paradits noapaloti.";
     cout << endl << "Ievadiet skaitli 1.23456789: ";
//     cin >> d;
     d = 1.23456789;
     cout << endl << "Izprintesim tagad: ";
     cout << endl << d;
     cout << endl << "Tagad cout izprinte so skaitli ar 5 cipariem aiz komata.";
     cout << endl << "Tatad, svarigs kopejais )nevis tikai to, kas ir aiz komata) ciparu skaits";
     cout << endl;
     cout << endl << "Varam ari uzlikt precizitati (teikism, 3) un izprintet";
     cout.precision(3);
     cout << endl << d;
     cout << endl << "3 cipari, bet - aiz komata:";
     cout.setf (ios::fixed);
     cout << endl << d;     
     cout << endl << "SCIENTIFC formata: ";
     cout.setf (ios::scientific);
     cout << endl << d << endl;
     cout << "Var noradit izdrukajamas apgabala garumu:";
     cout.width(7);
     cout << endl << d;
     cout << endl << "Tas gan darbojas tikai vienu reizi:";
     cout << endl << d;
     cout << endl << "Tuksumus var aizpildit:";
     cout.width(7);
     cout.fill ('-');
     cout << endl << d;
     cout << endl << "Var izlidzinat pec kreisas malas:";
     cout.setf (ios::left);
     cout.width(7);
     cout.fill ('-');
     cout << endl << d << endl;;      

     cout << endl << "Formatesanu var konfiguret turpat starp cout parametriem, bet tad japiesledz iomanip:";     
     cout << endl << setfill('-') << setprecision(3) << fixed << setw(7) << left << d << "#" << endl;
     cout << endl << setprecision(5) << d << "@" << endl;         
}

int lab_02_5_1_3rdnumber(int N)
{
    // Izveidot C++ programmu ar attiecîgajiem nosacîjumiem, izmantojot aritmçtiskas darbîbas (+ ,- ,* , /, %). 
    // Aritmçtisku darbîbu vietâ neizmantot simbolu virkòu apstrâdes operâcijas!
    // Uzdevums #1. Dots vesels pozitîvs skaitlis N, lielâks vai vienâds ar 100. 
    // Izmantojot aritmçtiskas operâcijas, izrçíinât treðo ciparu no beigâm. Piemçrs. N=123456; Rezultâts=4.
    int hundreds = N/100;
    int thousands = hundreds/10;
    return hundreds - thousands*10;
}
void lab_02_5_1_3rdnumber_test()
{
     test("lab_02_5_1 123546", 4, lab_02_5_1_3rdnumber(123456));
     test("lab_02_5_1 1", 1, lab_02_5_1_3rdnumber(100));
}
int lab_02_5_2_division(int M, int N)
{
    // Uzdevums #2. Doti veseli skaitïi M un N. Neizmantojot veselo skaitïu dalîðanu (int / int) 
    // un atlikuma operâciju (%), izrçíinât ðo skaitïu (1) veselo dalîjumu. 
    // Papildus ieteicams izmantot iebûvçtâs noapaïoðanas funkcijas floor(?) un ceil(?), kas atrodas bibliotçkâ <cmath> vai <math.h>.
    // todo
    return M/N;
}
void lab_02_5_2_division_test()
{
     test("lab_02_5_2_division", 2, lab_02_5_2_division(10, 5));
     test("lab_02_5_2_division", 1, lab_02_5_2_division(6, 5));
     test("lab_02_5_2_division", 0, lab_02_5_2_division(5, 10));
}
int lab_02_5_2_remainder(int M, int N)
{
    //Uzdevums #2. Doti veseli skaitïi M un N. Neizmantojot veselo skaitïu dalîðanu (int / int) 
    // un atlikuma operâciju (%), izrçíinât ðo skaitïu (2) dalîjuma atlikumu. 
    // Papildus ieteicams izmantot iebûvçtâs noapaïoðanas funkcijas floor(?) un ceil(?), kas atrodas bibliotçkâ <cmath> vai <math.h>.
    // todo
}
void lab_03_01_datatypes()
{
    cout.fill (' ');
    cout.setf (ios::right);
    char c1 = 'F', c2;
    int i1 = 50, i2;
    double d1 = 123e-3, d2;
    bool b1 = true, b2 = false;
    char *s1 = "Hallo, World!";

    cout << setw(10) << c1 << endl;
    cout << setw(10) << i1 << endl;
    cout << setw(10) << d1 << endl;
    cout << setw(10) << b1 << setw(10) << b2 << endl;
    cout << setw(10) << s1 << endl;
    
    c2 = i1;
    i2 = c1;

    cout << setw(10) << c2 << endl;
    cout << setw(10) << i2 << endl;
    
    cout << c1 << " " << sizeof(c1) << endl;
    cout << i2 << " " << sizeof(i2) << endl;   
    
    d2 = d1 * 100;
    cout << d1 << " " << d2 << endl;
    b1 = (d1 < d2);
    b2 = !b1;
    cout << d1 << " less than " << d2 << ": " << b1 << endl;
    cout << d1 << " greater or equal than " << d2 << ": " << b2 << endl; 
    
    cout << "d1<d2 " << b1 << " " << (b1 ? "true" : "false") << endl;
    cout << "d1>=d2 " << (d1>=d2) << " " << (d1>=d2 ? "true" : "false") << endl;    
    
    d2 = i1;
    cout << d2 << endl;

    // will generate warning, but proceed
//    i2 = d1;
    cout << i2 << endl;
    
//    i2 = ceil (d1);
    cout << i2 << endl;    
    
    i2 = (int)ceil (d1);
    cout << i2 << endl;    
}
double lab_03_02_calculating(double a, double b, double c)
{
//    return a + b * c;
//    return (a + b) * c;
// Dalîðanai izmantojot ‘/’, sinusa iegûðanai fukciju sin(x), kosinusa iegûðanai fukciju cos(x), 
// bet pakâpçs iegûðanai funkciju pow(x,y), uzrakstît rindiòas d = (a + b) * c; vietâ:
    double result;
    result = ((a + sin(b)) / (b + cos(c))) + pow(b, a+c); // aprekinam precizo vertibu
    result = round(result * 1000); // lai dabut 729913 no 729912.53(..)
    return result/1000;
}
void lab_03_02_calculating_test() 
{
     test("lab_03_02_calculating", 729.913, lab_03_02_calculating(2, 3, 4));
}
bool lab_04_01_if (int a)
{
    if (a <= 0) cout << "mazais" << endl;
    else cout << "LIELAIS" << endl;
    return a <= 0;
} 
void lab_04_01_if_test()
{
     test("lab_04_01_if", false, lab_04_01_if(5));     
     test("lab_04_01_if", true, lab_04_01_if(-5));     
}
string lab_04_02 (int a)
{
    if (a > 0)          return "LIELAIS";
    else if (a == 0)    return "n-u-l-l-e";
    else                return "mazais";
}
string lab_04_02a (int a)
{
    // Pârveidot programmu lab_04_02 par funkcionâli identisku programmu tâ, 
    // ka tiek izmantotas salîdzinâðanas operâcijas < un != (mazâks un nav vienâds) ..
    // .. – iepriekð izmantoto operâciju > un == vietâ.
    if (a < 0)          return "mazais";
    else if (a != 0)    return "LIELAIS";
    else                return "n-u-l-l-e";
}
string lab_04_02b (int a)
{
    // Pârveidot programmu lab_04_02 par funkcionâli identisku programmu tâ, 
    //  ka tiek izmantotas salîdzinâðanas operâcijas < un >.
    if (a < 0)          return "mazais";
    else if (a > 0)     return "LIELAIS";
    else                return "n-u-l-l-e";
}
string lab_04_02c (int a)
{
    // Pârveidot programmu lab_04_02 par funkcionâli identisku programmu tâ, 
    //  ka tiek izmantota tikai viena veida salîdzinâðanas operâcija <
    if (a < 0)          return "mazais";
    else if (a < 1)     return "n-u-l-l-e";
    else                return "LIELAIS";
}
string lab_04_02d (int a)
{
    // Pârveidot programmu lab_04_02 par funkcionâli identisku programmu tâ, 
    //  ka tiek izmantota tikai viena veida salîdzinâðanas operâcija >
    if (a > 0)          return "LIELAIS";
    else if (a > -1)     return "n-u-l-l-e";
    else                return "mazais";
}
void lab_04_02_test()
{
     test("lab_04_02", "LIELAIS",    lab_04_02(5));          
     test("lab_04_02", "mazais",     lab_04_02(-5));          
     test("lab_04_02", "n-u-l-l-e",  lab_04_02(0));          
     
     test("lab_04_02a", "LIELAIS",   lab_04_02a(5));          
     test("lab_04_02a", "mazais",    lab_04_02a(-5));          
     test("lab_04_02a", "n-u-l-l-e", lab_04_02a(0)); 
              
     test("lab_04_02b", "LIELAIS",   lab_04_02b(5));          
     test("lab_04_02b", "mazais",    lab_04_02b(-5));          
     test("lab_04_02b", "n-u-l-l-e", lab_04_02b(0)); 
              
     test("lab_04_02c", "LIELAIS",   lab_04_02c(5));          
     test("lab_04_02c", "mazais",    lab_04_02c(-5));          
     test("lab_04_02c", "n-u-l-l-e", lab_04_02c(0)); 
     
     test("lab_04_02d", "LIELAIS",   lab_04_02d(5));          
     test("lab_04_02d", "mazais",    lab_04_02d(-5));          
     test("lab_04_02d", "n-u-l-l-e", lab_04_02d(0)); 
}
string lab_04_03 (int a)
{
    if (a > 0)
    {
        if (a > 9) return "LIELAIS PLUS";
        else       return "mazais plus";
    }
    else
    {
        if (a < -9) return "LIELAIS -";
        else if (a < 0) return "mazais -";
        else return "n-u-l-l-e";
    };
}
string lab_04_03a (int a)
{
    if (a > 9) return "LIELAIS PLUS";
    else if (a > 0) return "mazais plus";
    else if (a < -9) return "LIELAIS -";
    else if (a < 0) return "mazais -";
    else return "n-u-l-l-e";
}
void lab_04_03_test()
{
     test("lab_04_03_test", "mazais plus",  lab_04_03(5));
     test("lab_04_03_test", "LIELAIS PLUS", lab_04_03(15));
     test("lab_04_03_test", "n-u-l-l-e",    lab_04_03(0));
     test("lab_04_03_test", "mazais -",     lab_04_03(-5));
     test("lab_04_03_test", "LIELAIS -",    lab_04_03(-15));
     
     test("lab_04_03a_test", "mazais plus",  lab_04_03a(5));
     test("lab_04_03a_test", "LIELAIS PLUS", lab_04_03a(15));
     test("lab_04_03a_test", "n-u-l-l-e",    lab_04_03a(0));
     test("lab_04_03a_test", "mazais -",     lab_04_03a(-5));
     test("lab_04_03a_test", "LIELAIS -",    lab_04_03a(-15));
}
int lab_04_04_for ()
{
    int a = 0;
    for (int i=0; i<5; i++)
    {
        a = a + i;
    };
    return a;
}

int lab_04_04_for_break ()
{
    int a = 0;
    for (int i=0; i<5; i++)
    {
        if (i == 2) break;
        a = a + i;
    };
    return a;
}

int lab_04_04_for_continue ()
{
    int a = 0;
    for (int i=0; i<5; i++)
    {
        if (i == 3) continue;
        a = a + i;
    };
    return a;
}
void lab_04_04_for_test()
{
     test("lab_04_04_for", 10,  lab_04_04_for());
     test("lab_04_04_for_break", 1,  lab_04_04_for_break());
     test("lab_04_04_for_continue", 7,  lab_04_04_for_continue());
}
int lab_04_05_1(int a, int b)
{
//     Doti 2 veseli skaitïi a, b.
//     Ja abi ir mazâki par 0, tad izdrukât to reizinâjumu,
//     citâdi izdrukât to summu
       if (a < 0)
          if (b < 0)          // NB: lidz sim "&&" nebija ieviests
             return a * b;
       ;
       return a + b;
}
void lab_04_05_1_test()
{
     test("lab_04_05_1", 3,  lab_04_05_1(1, 2));
     test("lab_04_05_1", 2,  lab_04_05_1(-1, -2));
     test("lab_04_05_1", -1,  lab_04_05_1(1, -2));
}

string lab_04_05_2_help(int low, int middle, int high)
{
       // si funkcija maces noskaidrot, 
       // kuram skaitlim  - lielakajam vai mazakajam - 
       // ir tuvaks videjais skaitlis
       int to_high = abs(middle - high);
       int to_low  = abs(middle - low);       

       if      (to_high < to_low) return "tuvak lielakajam";
       else if (to_low < to_high) return "tuvak mazakajam";
       else return "vienada attaluma";
}   
string lab_04_05_2(int a, int b, int c)
{
    int middle;
    //Doti 3 veseli atðíirîgi skaitïi a, b, c.
    //Atrast pçc lieluma vidçjo skaitli un noskaidrot,
    //vai tâ vçrtîba ir tuvâka lielajam vai mazajam skaitlim.
    
    // tatad, ispejamie varianti: a, b vai c
    // a: vai nu b <= a <= c, vai nu c <= a <= b
    if (a >= b)
       if (a <= c)
          // padodam paligfunkcijai jau sakartotu 
          // int. sarakstu
          return lab_04_05_2_help(b, a, c);          
          
    if (a >= c)
       if (a <= b)
          return lab_04_05_2_help(c, a, b);
    // analogiski, ar b un c          
    if (b >= a)
       if (b <= c)
          return lab_04_05_2_help(a, b, c);
    if (b >= c)
       if (b <= a)
          return lab_04_05_2_help(c, b, a);

    if (c >= a)
       if (c <= b)
          return lab_04_05_2_help(a, c, b);
    if (c >= b)
       if (c <= a)
          return lab_04_05_2_help(b, c, a);
          
    return "";
}
string lab_04_05_2_bubble (int a, int b, int c)
{
    int tmp;
     // sort numbers a,b,c a=least, c=greatest:
    if (a > b) { tmp = a; a = b; b = tmp; };
    if (b > c) { tmp = b; b = c; c = tmp; };
    if (a > b) { tmp = a; a = b; b = tmp; };
    // determine output:
    if (b - a == c - b) return "vienada attaluma";
    else if (b - a < c - b) return "tuvak mazakajam";
    else return "tuvak lielakajam";
}    
void lab_04_05_2_test()
{          
     test("lab_04_05_2", "vienada attaluma", lab_04_05_2(1, 2, 3));
     test("lab_04_05_2", "tuvak mazakajam",  lab_04_05_2(-7, 2, -5));
     test("lab_04_05_2", "tuvak lielakajam", lab_04_05_2(-7, 2, 5));

     test("lab_04_05_2_bubble", "vienada attaluma", lab_04_05_2_bubble(1, 2, 3));
     test("lab_04_05_2_bubble", "tuvak mazakajam",  lab_04_05_2_bubble(-7, 2, -5));
     test("lab_04_05_2_bubble", "tuvak lielakajam", lab_04_05_2_bubble(-7, 2, 5));     
}
int lab_04_05_03_findnegative(int a, int b, int c)
{
    //Doti 3 veseli skaitli a, b, c.
    //Noskaidrot, vai starp tiem ir negativi skaitli,
    //un ja ir, kurs starp negativajiem ir lielakais.
    //Piemers #1. a=1, b=2, c=3; Nav negativu skaitlu. - atgriezt 0
    //Piemers #2. a=7, b=-2, b=-5; rezultats -2.
    
    if ((a > 0) && (b > 0) && (c > 0)) return 0; // nav negativu skaitlu - atgriezam 0

    int tmp;
    // sortejam skaitlus
    if (a > b) {tmp = a; a = b; b = tmp;};   // vertibu apmaina starp mainigajiem, izmantojot paligmainigo
    if (b > c) {b = b+c; c = b-c; b = b-c;}; // vertibu apmaina starp mainigajiem, neizmantojot paligmainigo
    if (a > b) {swap(a, b);};                // vertibu apmaina starp mainigajiem, izmantojot iebuveto funkciju

    
    // tagad skaitli ir sakartoti augosa seciba: a, b, c
    // ejam no augsas (c, b, a) - pirmais negativais ari bus lielakais negativais
    if (c < 0) return c;
    if (b < 0) return b;
    if (a < 0) return a;        
}
void lab_04_05_03_findnegative_test()
{
    test("lab_04_05_03_findnegative",  0, lab_04_05_03_findnegative(1, 2, 3));     
    test("lab_04_05_03_findnegative", -2, lab_04_05_03_findnegative(7, -2, -5));     
}
int lab_04_06_1_stars(int rows)
{
//    Doti naturâls skaitlis n.
//    Izdrukât figûru no zvaigznîtçm ‘*’, kas sastâv no n rindiòâm tâdçjâdi, 
//    ka pirmajâ rindâ ir 1 zvaigznîte, otrajâ rindâ – 2, treðajâ 3, tad atkal 1, 2, 3 utt.
//    plus - atgriezt pedejas rindas zvaigznisu skaitu
      int stars_in_row;
      for(int i = 1; i <= rows; i++)
      {
              // saskaitam, cik zvaigznu japrinte
              stars_in_row = (i-1)%3 + 1;
              for (int j = 1; j <= stars_in_row; j++)
              {
                  cout << "*";
              }
              cout << endl;
      }    
      return stars_in_row;
}
void lab_04_06_1_stars_test()
{
     test("lab_04_06_1_stars",  1, lab_04_06_1_stars(10));     
}
int lab_04_06_2_addodds(int n)
{
    //Doti naturâls skaitlis n.
    //Izmantojot for ciklu un elementu saskaitîðanu, aprçíinât un izdrukât pirmo n nepâra skaitïu summu.
    //Piemçrs. n=10; rezultâts: 100
    //(jo 1+3+5+7+9+11+13+15+17+19=100)    
    
    int sum = 0;     // seit skaitlus SUMMESIM
    int count;       // seit skaitlus SKAITISIM (cik nepara skaitlus jau atradam)
    int number = 0;  // seit glabasim sobrid apskatamo skaitli
    
    // FOR cikla nosacijumos tresais parametrs tukss - ..
    // .. count++ daram tikai tad, kad atrodam nepara skaitli
    for (count = 0; count < n; ) 
    {
        number++; // skatamies nakamo skaitli
        if (number%2!= 0) // ja tas ir nepara - tas mus interese! ejam IF ieksaa
        {
           sum += number; // summejam to
           count++;       // un iegaumejam, ka vienu no n esam atradusi
        }
    }    
    return sum;
}
int lab_04_06_2_addodds_cool(int n)
{
    // risina to pasu uzdevumu, bet tikai ar interesantakiem FOR nosacijumiem
    int sum = 0;
    
    for (int count = 0, number = 1; count < n; count++, number += 2 ) 
    {
           sum += number;
    }    
    return sum;
}
void lab_04_06_2_addodds_test()
{
     test("lab_04_06_2_addodds",       100, lab_04_06_2_addodds(10));
     test("lab_04_06_2_addodds_cool",  100, lab_04_06_2_addodds_cool(10));          
}
string lab_05_01_initial(int a)
{
    if (a >= 0 && a <= 9) return "LABAIS";
    else return "sliktais";
}
string lab_05_01_modified(int a)
{
    // Parveidot programmu ta, lai, nemainot tas darbibu, izpilditos sadas prasibas: 
    // (a) izveles nosacijuma netiktu izmantots &&, 
    // (b) joprojam butu tikai viens izveles nosacijums (nelietot else if)
    if ((a < 0) || (a > 9)) return "sliktais";
    else return "LABAIS";
}
void lab_05_01_test()
{
     test("lab_05_01_initial", "sliktais", lab_05_01_initial(-5));
     test("lab_05_01_initial", "LABAIS",   lab_05_01_initial(5));
     test("lab_05_01_initial", "sliktais", lab_05_01_initial(15));
     
     test("lab_05_01_modified", "sliktais", lab_05_01_modified(-5));
     test("lab_05_01_modified", "LABAIS",   lab_05_01_modified(5));
     test("lab_05_01_modified", "sliktais", lab_05_01_modified(15));     
}
int lab_05_02_loop_for()
{
    int sum = 0, i, n = 10;
    for (i=1; i<=10; i++)
    {
        sum += i;
    };
    return sum;
}
void lab_05_02_loop_for_test()
{
     test("lab_05_02_loop_for", 55, lab_05_02_loop_for());     
}

  class skaitlis
  {
    string x;
    int y;
    public:    
    skaitlis (const string &a, int b) { x=a; y=b; };
    void print ()
    {
        cout << x << endl;
        cout << y << endl;
    };
    void change (const string &a, int b) { x=a; y=b; };
  };

void lab16_1()
{
    skaitlis s1 ("pieci", 5);
    s1.print ();
    s1.change ("desmit", 10);
    s1.print ();
};


///////////////////////////////////////////////////////////////////
// laboratorijas darbi
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
// katrs labs sauc attieciga laboratorijas darba uzdevumu testus
void lab01 ()
{
     lab_01_1_hello_test();
     lab_01_2_add_test();
}
void lab02 ()
{    
     lab_02_1_escapes_test(); 
     lab_02_2_types_test();
//     lab_02_3_format_test();
     lab_02_4_format();
     lab_02_5_1_3rdnumber_test();
     lab_02_5_2_division_test();
}
void lab03()
{
     lab_03_01_datatypes();
     lab_03_02_calculating_test();
}
void lab04()
{
     lab_04_01_if_test();  
     lab_04_02_test();
     lab_04_03_test();
     lab_04_04_for_test();
     lab_04_05_1_test();
     lab_04_05_2_test();
     lab_04_05_03_findnegative_test();
     lab_04_06_1_stars_test();
     lab_04_06_2_addodds_test();
}
void lab05()
{
     lab_05_01_test();
     lab_05_02_loop_for_test();
}
void lab06(){}
void lab07(){}
void lab08(){}
void lab09(){}
void lab10(){}
void lab11(){}
void lab12(){}
void lab13(){}
void lab14(){}
void lab15(){}
void lab16()
{
     lab16_1();
}
void lab17(){}
void lab18(){}
void lab19(){}
void lab20(){}
void lab21(){}

///////////////////////////////////////////////////////////////////
// main - programmas "galvena ieeja"; izsauc laboratorijas darbus
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
int main()
{
//    lab01();
//    lab02();
//    lab03();
//    lab04();
//    lab05();
    lab06();
    lab07();
    lab08();
    lab09();
    lab10();
    lab11();
    lab12();
    lab13();
    lab14();
    lab15();
    lab16();
    lab17();
    lab18();
    lab19();
    lab20();
    lab21();

    cout << endl;
    system("pause");
    return 0;
}
