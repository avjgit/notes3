// funkcijas nosaukumu formats: "lab_", laboratorijas darba nr, uzdevuma nr, apraksts
void lab1_1()
{
     return "Hello, world!";
}
// katram uzdevumam ir tests
void lab1_1_test()
{
     string expected = "Hello, world!";        // definejam velamo rezultatu (ko gribam no funkcijas sanemt?)
     string actual = lab_01_1_hello();         // pierakstam realo rezultatu (ko isteniba esam sanemusi)
     test("lab_01_1_hello", expected, actual); // padodam to visu funkcijai, kas prot to apstradat
                                               // un lai vina pasaka mums rezultatu
}                                               
