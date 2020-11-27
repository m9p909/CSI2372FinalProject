#include "../main.h"

int hello()
{
  cout << "Hello, World!" << endl;
  return 0;
}

int gameStartMessage()
{
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
  promptEnterToContinue();
  cout << endl;
  cout << endl;
  return 0;
}

/**
 * Presents the user with a prompt asking them to press enter to continue.
 */
int promptEnterToContinue()
{
  cout << "~ Please press ENTER to continue...\n";
  // TODO: Uncomment when ready to submit project, recomment for dev.
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return 0;
}