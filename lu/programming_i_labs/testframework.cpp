-
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
// tas pats tests, tikai ciparu tipa rezultatiem
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
