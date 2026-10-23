## **💻 문제 정의**

https://school.programmers.co.kr/learn/courses/30/lessons/12936

## **💡 접근 및 설계**

한 수를 맨 앞에 배치하면, 나머지 수로 만들 수 있는 가짓수는 (n-1)!이다.

예를 들어 수가 1, 2, 3 세 개라면, 1을 맨 앞에 두었을 때 가능한 가짓수는 2! = 2이다. 2나 3을 맨 앞에 두어도 마찬가지다. 그러니 1로 시작하는 순열은 1~2번째, 2로 시작하는 순열은 3~4번째, 3으로 시작하는 순열은 5~6번째가 된다.

이렇게 맨 앞 자리부터 하나씩 정해 나가면 된다. i번째 자리를 정할 때, 뒤에 남은 수로 만들 수 있는 가짓수는 (n-1-i)!개이므로, k를 (n-1-i)!로 나눈 몫이 남은 수 중 몇 번째 수를 놓을지를 뜻한다. 그 수를 놓은 뒤 남은 수 목록에서 지우고, 나머지를 새로운 k로 삼아 다음 자리를 정한다.

단, k는 1부터 세지만 나눗셈은 0부터 세야 몫이 맞게 나온다. 예를 들어 1~2번째가 첫 번째 묶음인데, 그대로 나누면 2÷2=1이 되어 두 번째 묶음으로 잘못 계산된다. 그래서 처음에 k에서 1을 빼서 0부터 세는 번호(0~1, 2~3, 4~5)로 맞춘 뒤 나눈다.

### **✏️ 알고리즘 풀이**

-

### **🗒️ 최종 제출 코드**

```cpp
#include <string>
#include <vector>

using namespace std;

long long factorial(int n){
    long long res = 1;
    for(int i=2; i<=n; i++) res *= i;
    return res;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> nums;
    for(int i=1; i<=n; i++) nums.push_back(i);
    
    long long v = factorial(n-1);
    k--;
    
    for(int i=0; i<n-1; i++){
        long long q = k / v;
        long long r = k % v;
        answer.push_back(nums[q]);
        nums.erase(nums.begin() + q);
        k = r;
        v /= n-1-i;
    }
    answer.push_back(nums[0]);
    return answer;
}
```