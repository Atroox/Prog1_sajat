#include <iostream>
#include <queue>

using namespace std;

void showq(queue<int> gg)
{
	queue<int> q = gg;
	while(!q.empty()){
			cout << " " << q.front();
			q.pop();
	}
	cout << endl;

}

int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
		
	cout << "The queue q is: ";
	showq(q);

	cout << "\nq.size(): " <<q.size();
	cout << "\nq.front(): " <<q.front();
	cout << "\nq.back(): " <<q.back();

	cout << "\nq.pop(): ";
	q.pop();
	showq(q);


	return 0;
}