#include <iostream>
#include <set>
using namespace std;
int main ()
{
  int myints[] = {75,23,65,42,13};
  set<int> myset (myints,myints+5);

 /* cout << "myset contains:";
  for (set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
    cout << ' ' << *it;

  cout << '\n';
    set<int>:: iterator it;
    it=myset.begin();
  cout<<*it<<endl;*/

set<int>:: iterator it;
 for (it=myset.cb; it != myset.cend(); ++it)
    cout << ' ' << *it;


  return 0;
}
