#include "../main.h"
#include "doctest.h"

TEST_CASE("Write and Read a file.")
{
    string testString = "Hooray, we can read and write files with C++!";
    string filename = "unit-test.txt";

    // Write to file
    ofstream outFile(filename);
    outFile << testString;
    outFile.close();

    // Read Back
    ifstream inFile(filename);
    stringstream x;
    x << inFile.rdbuf();
    inFile.close();
    CHECK(x.str() == testString);
}