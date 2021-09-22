/* Assignment: 1
Author : Hai Elazari, ID : 314794751 */

#include <iostream>
#include "game.h"
using namespace std;


int main() {
		char name1[60], name2[60];
		cout << "enter the first name: " << endl;
		cin >> name1;
		cout << "enter the second name: " << endl;
		cin >> name2;
		Game game(name1, name2);
		game.play();
		return 0;
}
