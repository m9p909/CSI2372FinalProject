#include "../main.h"

int hello()
{
  cout << "Hello, World!" << endl;
  return 0;
}

int gameStartMessage()
{
  cout << endl;
  cout << endl;
  cout << "CSI2372-A Fall 2020 - Final Project - Clarke, Fleck" << endl;
  cout << "Welcome to our implementation of the CSI2372 final project." << endl;
  // TODO: Add more messages for TAs if required.
  promptEnterToContinue();
  return 0;
}

int copyrightMessage()
{
  cout << "\n\nCSI2372-A Fall 2020 - Final Project - Due December 4, 2020, 2400h." << endl;
  cout << "Copyright (C) 2020 Ryan Fleck, Jack Clarke - Not licensed for reuse." << endl;
  cout << "==========================================================================" << endl;
  cout << endl;
  cout << "THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR" << endl;
  cout << "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY," << endl;
  cout << "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE" << endl;
  cout << "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER" << endl;
  cout << "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING" << endl;
  cout << "FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER" << endl;
  cout << "DEALINGS IN THE SOFTWARE." << endl;
  cout << endl;
  cout << "Do you understand the terms of use for this software?";
  bool continue_execution = promptYesOrNo();
  if (!continue_execution)
    throw UserDidntUnderstandTermsOfUse();
  return 0;
}

int logo()
{
  cout << endl;
  cout << "____ ____ ____ ___  ____ ____ _  _ ____" << endl;
  cout << "|    |__| |__/ |  \\ | __ |__| |\\/| |___" << endl;
  cout << "|___ |  | |  \\ |__/ |__] |  | |  | |___" << endl;
  cout << endl;
  return 0;
}

/**
 * Presents the user with a prompt asking them to press enter to continue.
 */
int promptEnterToContinue()
{
  cout << "~ Please press ENTER to continue...";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << endl;
  return 0;
}

// From StackOverflow: https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring

// trim from start (in place)
static inline void ltrim(std::string &s)
{
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
            return !std::isspace(ch);
          }));
}

// trim from end (in place)
static inline void rtrim(std::string &s)
{
  s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
          }).base(),
          s.end());
}

// Trims input and returns as a string.
string promptString()
{
  string input;

  // Don't accept blank input.
  do
  {
    cout << " (str) ?> ";
    cin >> input;
    ltrim(input);
    rtrim(input);
  } while (input == "" || input.length() == 0);

  cout << "~User typed \"" << input << "\"" << endl;
  cout << endl;
  return input;
}

/**
 * Presents the user with a prompt asking them to press enter to continue.
 */
bool promptYesOrNo()
{
  string input;
  do
  {
    cout << " (Y/n) ?> ";
    cin >> input;
    input = tolower(input[0]);
  } while (input != "y" && input != "n");
  cout << "~User typed \"" << input << "\"" << endl;
  cout << endl;
  return input == "y";
}

/**
 * Presents the user with a prompt asking them to press enter to continue.
 */
bool promptAOrB()
{
  string input;
  do
  {
    cout << " (A/B) ?> ";
    cin >> input;
    ltrim(input);
    rtrim(input);
    input = tolower(input[0]);
  } while (input != "a" && input != "b");
  cout << "~User typed \"" << input << "\"" << endl;
  cout << endl;
  return input == "a";
}