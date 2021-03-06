#include <iostream>
#include <sstream> // required for ostringtream
#include <iomanip>
#include <math.h>
using namespace std;
///////////////////////////////////////////////////////////////////
// "test" - paligfunkcija testesanai rezultatu parbaudei un izvadei
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
// si ir paligfunkcija testa rezultatu izvadei uz ekrana
void print_test_result(
    string description,
    string expected,
    string actual,
    string result
)
{
    // dazadiem parametriem jacensas izmantot constantes,
    // nevis harcodetas vertibas.
    // to izmantosim cout.width izsaukumos,
    // lai izlidzinatu dazada garuma tekstu izvadi
    const int width1 = 12;
    const int width2 = 16;

    // izlidzinam pec kreisas malas
    cout.setf (ios::left);

    cout << "tested ";
    cout.width(width1);
    cout << description + ": ";
    cout << result;
    cout << "| expected: ";
    cout.width(width2);
    cout << expected;
    cout << "received: ";
    cout << actual << endl;
}
void test(
     string description, // testa apraksts
     string expected,    // testa velamais rezultats
     string actual       // testa realais rezultats
)
{
    string result = "FAILED";  // pec noklusejuma, testa rezultats ir neveiksmigs
    if (expected == actual)    // parbaudam, vai realais sakrit ar velamo
        result = "passed";     // ja sakrit - tad tests veiksmigi nokartots
    print_test_result(description, expected, actual, result);

}
// tas pats tests, tikai skaitlu tipa rezultatiem
// abas TEST funkcijas var saukties vienadi; kompilators pats sapratis, kuru izsaukt
// (ir gana gudrs, lai tos atskirtu pec ieejas parametru tipiem - signaturas)
void test(
     string description,
     double expected,
     double actual
)
{
    string result = "FAILED";
    if (expected == actual)
        result = "passed";

    // nakamas rindinas - tikai tadel, lai atkalizmantotu print_test_result.
    // tam mums vajag konvertet double parametrus uz string
    std::ostringstream osstream;

    osstream << expected;
    string s_expected = osstream.str(); //

    osstream.str("");                   // iztiram output stream

    osstream << actual;
    string s_actual = osstream.str();

    print_test_result(description, s_expected, s_actual, result);
}
///////////////////////////////////////////////////////////////////
// laboratorijas darbu uzdevumi ar testiem
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
// funkcijas nosaukumu formats: "lab", laboratorijas darba nr, "_", uzdevuma nr
string lab01_1 ()
{
    return "Hello, world!";
}
// katram uzdevumam ir tests
void lab01_1_test ()
{
     string expected = "Hello, world!"; // definejam velamo rezultatu (ko gribam no funkcijas sanemt?)
     string actual = lab01_1();         // pierakstam realo rezultatu (ko isteniba esam sanemusi)
     test("lab01_1", expected, actual); // padodam to visu funkcijai, kas prot to apstradat
                                        // un lai vina pasaka mums rezultatu
}
int lab01_2 (int x, int y)
{
    int z;
    z = x + y;
    return z;
}
void lab01_2_test ()
{
    int x, y;
    /*
    cout << "Input 2 integer values:" << endl;  // jautajam ieejas parametrus
    cin >> x >> y;                              // un saglabajam
    test("lab01_2 1", x + y, lab01_2(x, y));    // lab01_2 rezultatu var nesaglabat, bet padot uzreiz
    */
    // varam ari nejautat, bet pasi pieskirt vertibas
    x = -1;
    y = 1;
    test("lab01_2a", x + y, lab01_2(x, y));

    // varam dod skaitlus "pa taisno", nelietojot mainigos
    test("lab01_2b", 123 + 456, lab01_2(123, 456));
}
string lab02_1()
{
   return "HELLO\\, \"WORLD!\"";
}
void lab02_1_test()
{
    test("lab02_1", "HELLO\\, \"WORLD!\"", lab02_1());
}
double lab02_2()
{
    double x, y, z;
    x = 12;
    y = 7;
    z = x / y;
    return z;
}
void lab02_2_test()
{
    test("lab02_2", 12.0/7, lab02_2());
}
double lab02_3(
      string message,
      bool clean = false,
      int symbols = 256
)
{
    if (clean && !cin.good())
    {
        cin.clear();
        cin.ignore(symbols, '\n');
    }

    cout << message << endl;
    double d = 987;
    cout << "Input numeric value #1: ";
	cin >> d;
    cout << "Output: " << d << endl;

    if (clean && !cin.good())
    {
        cin.clear();
        cin.ignore(symbols, '\n');
    }

    cout << "Input numeric value #2: ";
	cin >> d;
    cout << "Output: " << d << endl;
    return d;
}
void lab02_3_test()
{
    float output;
    cout << endl;
    cout << "///////////////" << endl;
    cout << "/////////////// Laboratorijas darbs 2.3" << endl;
    cout << "///////////////" << endl;
    cout << "saja lab.darba nebus testu; vienkarsi paverojiet output";
    cout << endl << endl << endl;

    lab02_3("Ievadiet skaitlus - 1.23, tad nospiediet <Enter>, tad ievadiet 4.56");
    cout << "Tas ir vienkarss input/ output gadijums.";
    cout << endl << endl << endl;

    lab02_3("Tagad ievadiet tos pasus skaitlus viena reize, at atstarpi (un beigas <Enter>)");
    cout << "Ka redzat, input saprot skaitlu atdalisanu ar atstarpi.";
    cout << endl << endl << endl;

    lab02_3("Tagad ievadiet burtu");
    cout << "Ta ka jus ievadijat burtu, tad skaitlis netika nolasits, ";
    cout << "un mainigajam d palika sakotneja vertiba (987)";
    cout << ", un otraja reize ievadisana netika prasita, ";
    cout << "jo ievades plusma cin tika nobloketa un pirms nakosas darbibas ta ir jaatbloke.";
    cout << "To (atblokesanu) ari izdarisim nakosaja piemera. Atblokesanu var redzet programmas koda.";
    cout << endl << endl << endl;

    lab02_3("Tagad ievadiet burtu, <Enter>, pec tam ciparu 123", true);
    cout << "Ka redzat, CIN atblokesana palidz:)";
    cout << endl << endl << endl;

    lab02_3("Tagad ievadiet a123, <Enter>, tad ciparu 123", true);
    cout << "Tas pats, kas iepriekseja piemera";
    cout << endl << endl << endl;

    lab02_3("Un tagad velreiz ievadiet a123 (un <Enter>)", true, 1);
    cout << "Seit programma tika konfigureta ta, ka ignore pirmo ievadito simbolu";
    cout << ", bet visus nakamos uztver, ka ievadamo vertibu. No 'a123' tika panemts '123'.";
    cout << endl << endl << endl;

}
double lab02_4()
{
    cout << endl;
    cout << "///////////////" << endl;
    cout << "/////////////// Laboratorijas darbs 2.4" << endl;
    cout << "///////////////" << endl;
    cout << "saja lab.darba nebus testu; vienkarsi paverojiet output";
    cout << endl << endl << endl;

    double d;
    cout << endl << "Ievadiet skaitli 123.456789: ";
    cin >> d;
    // d = 123.456789;
    cout << endl << "Tads ir cout double tipa standarta izvades formats: ";
    cout << endl << d;
    cout << endl;
    cout << endl << "Redzam tikai 3 zimes aiz komata, ka ari - skaitlis tika paradits noapaloti.";
    cout << endl << "Ievadiet skaitli 1.23456789: ";
    cin >> d;
     // d = 1.23456789;
    cout << endl << "Izprintesim tagad: ";
    cout << endl << d;
    cout << endl << "Tagad cout izprinte so skaitli ar 5 cipariem aiz komata.";
    cout << endl << "Tatad, svarigs kopejais (nevis tikai to, kas ir aiz komata) ciparu skaits";
    cout << endl;
    cout << endl << "Varam ari uzlikt precizitati un izprintet." << endl;
    int precision;
    cout << endl << "Kadu precizitati gribat redzet? ";
    cin >> precision;
    cout << endl << "OK, seit ta bus:";
    cout.precision(precision);
    cout << endl << d;
    cout << endl << "Ka redzams, tie ir " << precision << " cipari kopa";
    cout << endl << ", bet drosi vien gaidijam, ka tie bus " << precision << "cipari aiz komata, vai ne?";
    cout << endl << "Tas ari ir izdarams:";
    cout.setf (ios::fixed);
    cout << endl << d;
    cout << endl << "Un te ir SCIENTIFC formata piemers:";
    cout.setf (ios::scientific);
    cout << endl << d << endl;
    cout << endl << "Vel var noradit izdrukajamas apgabala garumu.";
    int width;
    cout << endl << "Kadu gribat? ";
    cin >> width;
    cout.width(width);
    cout << endl << d;
    cout << endl << "Tas gan darbojas tikai vienu reizi:";
    cout << endl << d;
    cout << endl << "Vel fica - tuksumus var aizpildit.";
    char fillchar;
    cout << endl << "Ar kadu simbolu pildisim?";
    cin >> fillchar;
    cout.width(width);
    cout.fill (fillchar);
    cout << endl << d;
    cout << endl << "Vel - var izlidzinat pec kadas malas; teiksim, kreisas.";
    cout.setf (ios::left);
    cout.width(width);
    cout.fill (fillchar);
    cout << endl << d << endl;;

    cout << endl << "Formatesanu var konfiguret turpat starp cout parametriem";
    cout << endl << ", bet tad japiesledz iomanip biblioteka:";
    cout << endl << setfill(fillchar) << setprecision(precision) << fixed << setw(width) << left << d << endl;
}

int lab02_5_1(int N)
{
    // Izveidot C++ programmu ar attiecîgajiem nosacîjumiem, izmantojot aritmçtiskas darbîbas (+ ,- ,* , /, %).
    // Aritmçtisku darbîbu vietâ neizmantot simbolu virkòu apstrâdes operâcijas!
    // Uzdevums #1. Dots vesels pozitîvs skaitlis N, lielâks vai vienâds ar 100.
    // Izmantojot aritmçtiskas operâcijas, izrçíinât treðo ciparu no beigâm. Piemçrs. N=123456; Rezultâts=4.
    int hundreds = N/100;
    int thousands = hundreds/10;
    return hundreds - thousands*10;
}
void lab02_5_1_test()
{
     test("lab02_5_1a", 4, lab02_5_1(123456));
     test("lab02_5_1b", 1, lab02_5_1(100));
}
int lab02_5_2_division(int M, int N)
{
    // Uzdevums #2. Doti veseli skaitïi M un N. Neizmantojot veselo skaitïu dalîðanu (int / int)
    // un atlikuma operâciju (%), izrçíinât ðo skaitïu (1) veselo dalîjumu.
    // Papildus ieteicams izmantot iebûvçtâs noapaïoðanas funkcijas floor(?) un ceil(?), kas atrodas bibliotçkâ <cmath> vai <math.h>.

    // UZMANIBU! Sis nav korekts uzdevuma atrisinajums (tika prasits neizmantot "/")
    return M/N;
}
void lab02_5_2_division_test()
{
     test("lab02_5_2a", 2, lab02_5_2_division(10, 5));
     test("lab02_5_2b", 1, lab02_5_2_division(6, 5));
     test("lab02_5_2c", 0, lab02_5_2_division(5, 10));
}
int lab02_5_2_remainder(int M, int N)
{
    //Uzdevums #2. Doti veseli skaitïi M un N. Neizmantojot veselo skaitïu dalîðanu (int / int)
    // un atlikuma operâciju (%), izrçíinât ðo skaitïu (2) dalîjuma atlikumu.
    // Papildus ieteicams izmantot iebûvçtâs noapaïoðanas funkcijas floor(?) un ceil(?), kas atrodas bibliotçkâ <cmath> vai <math.h>.

    // UZMANIBU! Sis nav korekts uzdevuma atrisinajums (tika prasits neizmantot "/")
    return M%N;
}

void lab02_5_2_remainder_test()
{
     test("lab02_5_2d", 2, lab02_5_2_remainder(5, 3));
     test("lab02_5_2e", 1, lab02_5_2_remainder(4, 3));
     test("lab02_5_2f", 0, lab02_5_2_remainder(3, 3));
}
void lab03_1()
{
    cout << endl;
    cout << "///////////////" << endl;
    cout << "/////////////// Laboratorijas darbs 3.1" << endl;
    cout << "///////////////" << endl;
    cout << "saja lab.darba nebus testu; vienkarsi paverojiet output";
    cout << endl << endl << endl;

    cout.fill (' ');
    cout.setf (ios::right);
    char c1 = 'F', c2;
    int i1 = 50, i2;
    double d1 = 123e-3; //128 * 10^-3 (pakape -3)
    double d2;
    bool b1 = true, b2 = false;
    char *s1 = "Hallo, World!";

    cout << "///// Izprintesim char, int un double: " << endl;
    cout << setw(10) << c1 << endl;
    cout << setw(10) << i1 << endl;
    cout << setw(10) << d1 << endl;
    cout << endl << endl;
    cout << "///// Ta tiek izprinteti boolean TRUE un FALSE: " << endl;
    cout << setw(10) << b1 << setw(10) << b2 << endl;
    cout << endl << endl;
    cout << "///// Un teksta rindina (rinda ar char'iem): " << endl;
    cout << setw(10) << s1 << endl;
    cout << endl << endl;

    cout << "///// Tagad uztaisisim eksperimentu  - ierakstisim char tipa mainigaja int tipa vertibu" << endl;
    cout << "Ievadiet kadu skaitli: ";
    cin >> i1;
    cout << "Ok, saglabajam to ka char un izprintejam:";
    c2 = i1;
    cout << setw(10) << c2 << endl;
    cout << endl << endl;


    cout << "/////Un otradi - inta ierakstam characteru." << endl;
    cout << "Ievadiet kadu burtu: ";
    cin >> c1;
    i2 = c1;
    cout << "Re, kas sanak, ka ja mes pieskiram to int mainigajam un izprintejam: " << endl;
    cout << setw(10) << i2 << endl;

    cout << endl << endl << "///// ";
    cout << "Izprintesim char un int mainigo izmerus: " << endl;
    cout << c1 << " " << sizeof(c1) << endl;
    cout << i2 << " " << sizeof(i2) << endl;


    cout << endl << endl << "///// ";
    cout << "Un vel dazi piemeri: " << endl;
    d2 = d1 * 100;
    cout << d1 << " " << d2 << endl;

    cout << endl << endl << "///// ";
    cout << "Izprintesim abus skaitlus un bool tipa mainigos ('aizkulises' skatities kodaa): " << endl;
    b1 = (d1 < d2);
    b2 = !b1;
    cout << d1 << " less than " << d2 << ": " << b1 << endl;
    cout << d1 << " greater or equal than " << d2 << ": " << b2 << endl;

    cout << "d1<d2 " << b1 << " " << (b1 ? "true" : "false") << endl;
    cout << "d1>=d2 " << (d1>=d2) << " " << (d1>=d2 ? "true" : "false") << endl;

    d2 = i1;
    cout << d2 << endl;

    cout << endl << endl << "///// ";
    cout << "Saglabasim double ka int, un pameginasim izprintet: " << endl;
    i2 = d1;
    cout << i2 << endl;
    cout << "Kods kompilejas, bet ta nav pratiga doma - saglabat double int'aa,";
    cout << "jo int'am ir sauraks vertibu apgabals";

    cout << endl << endl << "///// ";
    cout << "Pameginasim izprintet double veselo dalu (funkcija ceil): " << endl;
    i2 = ceil (d1);
    cout << i2 << endl;

    cout << "Konvertesim ceil uz int?: " << endl;
    i2 = (int)ceil (d1);
    cout << i2 << endl;
}

double lab03_2(double a, double b, double c)
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
void lab03_2_test()
{
     test("lab03_2", 729.913, lab03_2(2, 3, 4));
}
bool lab04_1 (int a)
{
    if (a <= 0) cout << "mazais" << endl;
    else cout << "LIELAIS" << endl;
    return a <= 0;
}
void lab04_1_test()
{
     test("lab04_1", false, lab04_1(5));
     test("lab04_1", true, lab04_1(-5));
}
string lab04_2 (int a)
{
    if (a > 0)          return "LIELAIS";
    else if (a == 0)    return "n-u-l-l-e";
    else                return "mazais";
}
string lab04_2a (int a)
{
    // Pârveidot programmu lab04_2 par funkcionâli identisku programmu tâ,
    // ka tiek izmantotas salîdzinâðanas operâcijas < un != (mazâks un nav vienâds) ..
    // .. – iepriekð izmantoto operâciju > un == vietâ.
    if (a < 0)          return "mazais";
    else if (a != 0)    return "LIELAIS";
    else                return "n-u-l-l-e";
}
string lab04_2b (int a)
{
    // Pârveidot programmu lab04_2 par funkcionâli identisku programmu tâ,
    //  ka tiek izmantotas salîdzinâðanas operâcijas < un >.
    if (a < 0)          return "mazais";
    else if (a > 0)     return "LIELAIS";
    else                return "n-u-l-l-e";
}
string lab04_2c (int a)
{
    // Pârveidot programmu lab04_2 par funkcionâli identisku programmu tâ,
    //  ka tiek izmantota tikai viena veida salîdzinâðanas operâcija <
    if (a < 0)          return "mazais";
    else if (a < 1)     return "n-u-l-l-e";
    else                return "LIELAIS";
}
string lab04_2d (int a)
{
    // Pârveidot programmu lab04_2 par funkcionâli identisku programmu tâ,
    //  ka tiek izmantota tikai viena veida salîdzinâðanas operâcija >
    if (a > 0)          return "LIELAIS";
    else if (a > -1)     return "n-u-l-l-e";
    else                return "mazais";
}
void lab04_2_test()
{
     test("lab04_2", "LIELAIS",    lab04_2(5));
     test("lab04_2", "mazais",     lab04_2(-5));
     test("lab04_2", "n-u-l-l-e",  lab04_2(0));

     test("lab04_2a", "LIELAIS",   lab04_2a(5));
     test("lab04_2a", "mazais",    lab04_2a(-5));
     test("lab04_2a", "n-u-l-l-e", lab04_2a(0));

     test("lab04_2b", "LIELAIS",   lab04_2b(5));
     test("lab04_2b", "mazais",    lab04_2b(-5));
     test("lab04_2b", "n-u-l-l-e", lab04_2b(0));

     test("lab04_2c", "LIELAIS",   lab04_2c(5));
     test("lab04_2c", "mazais",    lab04_2c(-5));
     test("lab04_2c", "n-u-l-l-e", lab04_2c(0));

     test("lab04_2d", "LIELAIS",   lab04_2d(5));
     test("lab04_2d", "mazais",    lab04_2d(-5));
     test("lab04_2d", "n-u-l-l-e", lab04_2d(0));
}
string lab04_3 (int a)
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
string lab04_3a (int a)
{
    if (a > 9) return "LIELAIS PLUS";
    else if (a > 0) return "mazais plus";
    else if (a < -9) return "LIELAIS -";
    else if (a < 0) return "mazais -";
    else return "n-u-l-l-e";
}
void lab04_3_test()
{
     test("lab04_3a", "mazais plus",  lab04_3(5));
     test("lab04_3b", "LIELAIS PLUS", lab04_3(15));
     test("lab04_3c", "n-u-l-l-e",    lab04_3(0));
     test("lab04_3d", "mazais -",     lab04_3(-5));
     test("lab04_3e", "LIELAIS -",    lab04_3(-15));

     test("lab04_3f", "mazais plus",  lab04_3a(5));
     test("lab04_3g", "LIELAIS PLUS", lab04_3a(15));
     test("lab04_3h", "n-u-l-l-e",    lab04_3a(0));
     test("lab04_3i", "mazais -",     lab04_3a(-5));
     test("lab04_3j", "LIELAIS -",    lab04_3a(-15));
}
int lab04_4 ()
{
    int a = 0;
    for (int i=0; i<5; i++)
    {
        a = a + i;
    };
    return a;
}

int lab04_4_break ()
{
    int a = 0;
    for (int i=0; i<5; i++)
    {
        if (i == 2) break;
        a = a + i;
    };
    return a;
}

int lab04_4_continue ()
{
    int a = 0;
    for (int i=0; i<5; i++)
    {
        if (i == 3) continue;
        a = a + i;
    };
    return a;
}
void lab04_4_test()
{
     test("lab04_4a", 10,  lab04_4());
     test("lab04_4b", 1,  lab04_4_break());
     test("lab04_4c", 7,  lab04_4_continue());
}
int lab04_5a(int a, int b)
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
void lab04_5a_test()
{
     test("lab04_5a", 3,  lab04_5a(1, 2));
     test("lab04_5a", 2,  lab04_5a(-1, -2));
     test("lab04_5a", -1,  lab04_5a(1, -2));
}

string lab04_5b_help(int low, int middle, int high)
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
string lab04_5b(int a, int b, int c)
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
          return lab04_5b_help(b, a, c);

    if (a >= c)
       if (a <= b)
          return lab04_5b_help(c, a, b);
    // analogiski, ar b un c
    if (b >= a)
       if (b <= c)
          return lab04_5b_help(a, b, c);
    if (b >= c)
       if (b <= a)
          return lab04_5b_help(c, b, a);

    if (c >= a)
       if (c <= b)
          return lab04_5b_help(a, c, b);
    if (c >= b)
       if (c <= a)
          return lab04_5b_help(b, c, a);

    return "";
}
string lab04_5bbl (int a, int b, int c)
{
    // sort by bubble
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
void lab04_5b_test()
{
     test("lab04_5b", "vienada attaluma", lab04_5b(1, 2, 3));
     test("lab04_5b", "tuvak mazakajam",  lab04_5b(-7, 2, -5));
     test("lab04_5b", "tuvak lielakajam", lab04_5b(-7, 2, 5));

     test("lab04_5bbl", "vienada attaluma", lab04_5bbl(1, 2, 3));
     test("lab04_5bbl", "tuvak mazakajam",  lab04_5bbl(-7, 2, -5));
     test("lab04_5bbl", "tuvak lielakajam", lab04_5bbl(-7, 2, 5));
}
int lab04_5c(int a, int b, int c)
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
void lab04_5c_test()
{
    test("lab04_5c",  0, lab04_5c(1, 2, 3));
    test("lab04_5c", -2, lab04_5c(7, -2, -5));
}
int lab04_6a(int rows)
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
void lab04_6a_test()
{
     test("lab04_6a",  1, lab04_6a(10));
}
int lab04_6b(int n)
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
int lab04_6b_cool(int n)
{
    // risina to pasu uzdevumu, bet tikai ar interesantakiem FOR nosacijumiem
    int sum = 0;

    for (int count = 0, number = 1; count < n; count++, number += 2 )
    {
           sum += number;
    }
    return sum;
}
void lab04_6b_test()
{
     test("lab04_6b a",  100, lab04_6b(10));
     test("lab04_6b b",  100, lab04_6b_cool(10));
}
string lab05_1_initial(int a)
{
    if (a >= 0 && a <= 9) return "LABAIS";
    else return "sliktais";
}
string lab05_1_modified(int a)
{
    // Parveidot programmu ta, lai, nemainot tas darbibu, izpilditos sadas prasibas:
    // (a) izveles nosacijuma netiktu izmantots &&,
    // (b) joprojam butu tikai viens izveles nosacijums (nelietot else if)
    if ((a < 0) || (a > 9)) return "sliktais";
    else return "LABAIS";
}
void lab05_1_test()
{
     test("lab05_1a", "sliktais", lab05_1_initial(-5));
     test("lab05_1b", "LABAIS",   lab05_1_initial(5));
     test("lab05_1c", "sliktais", lab05_1_initial(15));

     test("lab05_1d", "sliktais", lab05_1_modified(-5));
     test("lab05_1e", "LABAIS",   lab05_1_modified(5));
     test("lab05_1f", "sliktais", lab05_1_modified(15));
}
int lab05_2()
{
    int sum = 0, i, n = 10;
    for (i=1; i<=10; i++)
    {
        sum += i;
    };
    return sum;
}
void lab05_2_test()
{
     test("lab05_2", 55, lab05_2());
}

void lab05_3()
{
    // Programma izprinte rezinajuma tabulu 4X4
    // beigas uz displeja jabut izprintetam:
    // 1 2  3  4
    // 2 4  6  8
    // 3 5  9 12
    // 4 8 12 16

    //outer cycle
    for (int i=1; i<=4; i++)
    {
    // Sets the number of characters to be used as the field width for the next insertion operation.
        for (int k=1; k<=4; k++)
        {
                cout << setw(4) << i*k;
        }
        cout << endl;
    };
}
void lab05_3a()
{
    // Mēģināt pārveidot programmu tā, lai tā izmantotu tikai viena līmeņa ciklu, bet veiktu precīzi tādu pašu darbu – izdrukātu reizrēķina tabulu 4X4 (lab05.3a.cpp).
    // Ieteikums: visticamāk, lai kompensētu iekšējo ciklu, nāksies izmantot papildus if operatoru, kā arī veselo skaitļu dalīšanas / un atlikuma % operācijas.
    //inner cycle
    for (int i = 0; i < 16; i++)
    {
        cout << setw(4) << (i/4+1) * (i%4+1);
        if (i%4 == 3) cout << endl;
    }
}
void lab05_4a()
{
    // Doti naturāls skaitlis n.
    // Izdrukāt „eglīti” no zvaigznītēm ‘*’, kas sastāv no n rindiņām tādējādi, ka pirmajā rindā ir 1 zvaigznīte, bet katrā nākamajā par vienu vairāk.
    // Piemērs. n=6; rezultāts:
    // *
    // **
    // ***
    // ****
    // *****
    // ******
    int rows;
    cout << "Cik rindu?";
    cin >> rows;
    for (int i = 1; i <= rows; i++)
    {
        for (int k = 1; k <= i; k++)
        {
            cout << '*';
        }
        cout << endl;
    }
}
void lab05_4b()
{
    int rows;
    int star_one;
    int star_two;

    cout << "Ievadiet naturalu nepara skaitli: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        star_one = i;
        star_two = rows-i+1;

        for (int k = 1; k <= rows; k++)
        {
            if (k == star_one)      cout << '*';
            else if (k == star_two) cout << '*';
            else                    cout << '-';
        }
        cout << endl;
    }

}
void lab05_4c()
{
        int rows;
    int star_one;
    int star_two;

    cout << "Ievadiet naturalu nepara skaitli: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int k = 1; k <= rows; k++)
        {
            if (k%3 == i%3) cout << '*';
            else          cout << '-';
        }
        cout << endl;
    }

}
///////////////////////////////////////////////////////////////////
// laboratorijas darbi
///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
// katrs labs sauc attieciga laboratorijas darba uzdevumu testus
void lab01 ()
{
     lab01_1_test();
     lab01_2_test();
}
void lab02 ()
{
     lab02_1_test();
     lab02_2_test();
     // todo: somehow skip 2.3 and 2.4
     // lab02_3_test();
     // lab02_4();
     lab02_5_1_test();
     lab02_5_2_division_test();
     lab02_5_2_remainder_test();
}
void lab03()
{
     // lab03_1();
     lab03_2_test();
}
void lab04()
{
     lab04_1_test();
     lab04_2_test();
     lab04_3_test();
     lab04_4_test();
     lab04_5a_test();
     lab04_5b_test();
     lab04_5c_test();
     lab04_6a_test();
     lab04_6b_test();
}
void lab05()
{
     lab05_1_test();
     lab05_2_test();
     lab05_3();
     lab05_3a();
     lab05_4a();

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
void lab16(){}
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
    lab01();
    lab02();
    lab03();
    lab04();
    lab05();
//    lab06();
//    lab07();
    lab08();
    lab09();
    lab10();
    lab11();
    lab12();
    lab13();
    lab14();
    lab15();
//    lab16();

    cout << endl;
    system("pause");
    return 0;
}
