

#include <iostream>

using namespace std;

main()
{
    cout << "hello world"<<endl;
    
    const int NUM_ENTRYS = 10;
    float num, avg, sum;
    // test = [];

    for(int i=0;i<NUM_ENTRYS;++i) {
        cin >> num;
        sum += num;
        // test.append(num)
    }
    avg = sum/NUM_ENTRYS;
    cout << "The average is: " << avg;
    
}

