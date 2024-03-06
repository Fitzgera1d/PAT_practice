### Linked-list

```c++
node* p = new node;
delete(p);
```

### `#include <stdio.h>`

- `scanf/printf`
| 数据类型    | 格  式  符 | 备        注  |
| ----------- | ---------- | ------------- |
| `int`       | `%d`       | `%0md`        |
| `long long` | `%lld`     |               |
| `float`     | `%f`       | `%.mf`        |
| `double`    | `%lf`      |               |
| `char`      | `%c`       | 可读` `、`\n` |
| `string`    | `%s`       | `%%`、`\\`    |

- `getchar/putchar`：可读换行符、`gets/puts`
- `sscanf`、`sprintf`
### `#include <math.h>`
- `fabs/abs`、`floor/ceil/round`
- `pow(double, double)`、`sqrt(double)`、`log`
- `cos/sin/tan`、`acos/asin/atan`
### `#include <string.h>`
- `memset(a, 0, sizeof(a))`、`strlen`、`strcmp`、`strcpy`、`strcat`

### `#include <bits/stdc++.h>`
- `typedef`：别名，`scanf != EOF`

```c++
const double eps = 1e-8;
const double Pi = acos(-1.0);

#define Equ(a, b) ((fabs((a) - (b))) < (eps))
#define More(a, b) (((a) - (b)) > (eps))
#define Less(a, b) (((a) - (b)) < (-eps))
#define MoreEqu(a, b) (((a) - (b)) > (-eps))
#define LessEqu(a, b) (((a) - (b)) < (eps))
```

### `#include <algorithm>`

```c++
#include <algorithm>
using namespace std;
max(x, y);
min(x, y);
abs((int)x);
swap(x, y);
reverse(it, it2);
next_permutation(it, it2);
fill(it, it2, value);
sort(it, it2[, cmp]);					// 可用于string, vector, deque, array
max_element(it, it2);
bool cmp(int a, int b) { return a > b; }
lower_bound(first, last, val); upper_bound();	// 用于有序容器
```

### Vector

```c++
#include <vector>
using namespace std;

vector<vector<int>> vi(3, vector<int>(4,1));// vector<int> Arrayname[arraysize];

vector<int> vi(size, val);				// vi.resize(size, val)
vector<vector<int>> vi;	
vector<int>::iterator it = vi.begin();	// vi[i] 等价于 *(vi.begin()+i)
for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++) {...}

vi.push_back(i);
vi.pop_back(i);
vi.size();
vi.clear();
vi.insert(it, x);
vi.erase(it);
vi.erase(first, last);					// 删除[first, last)
vi.clear();
```

### Set

```c++
#include <set>
using namespace std;
set<node> st;							// node是结构体类型
for(set<node>::iterator it = st.begin(); it != st.end(); it++) {...}
st.insert(x1);
st.find(x1) != st.end();				// 返回迭代器
st.erase(it);
st.erase(value);
st.erase(first, last);
st.size();
st.clear();
```

### String

```c++
#include <string>
#include <iostream>
using namespace std;
string str;
cin >> str;
cout << str;
printf("%s", str.c_str());				// 转换为char[]
for(string::iterator it = str.begin(); it != str.end(); it++) {...}
str.length(); str.size();
str += str2;
str.insert(3, str2);
str.insert(it, it2, it3);				// 插入[it2, it3)
str.erase(it);
str.erase(first, last);
str.erase(pos, length);
str.clear();
str.substr(pos, len);
str.find(str2) != string::npos;			// -1
str.replace(pos, len, str2);
str.replace(it1, it2, str2);
```

### Map

```c++
#include <map>
using namespace std;
map<char, int> mp;
mp['m'] = 20;
for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
	printf("%c %d", it->first, it->second);
}
map<char, int>::iterator it = mp.find('m');
mp.erase(it);
mp.erase(key);
mp.erase(first, last);
mp.size();
mp.clear();
```

### Queue & Priority_queue

```c++
#include <queue>
using namespace std;
queue<int> q;
q.push(2);
q.front() == q.back();
q.pop();
q.empty();
q.size();

priority_queue<int> q;
priority_queue<int, vector<int>, less<int>> q;
q.push(2);
q.top();
q.pop();
q.empty();
q.size();
struct fruit {
    string name;
    int price;
    friend bool operator < (fruit f1, fruit f2) {
        return f1.price < f2.price;
    }
}
```

### Stack

```c++
#include <stack>
using namespace std;
stack<int> st;
st.push();
st.top();
st.pop();
st.empty();
st.size();
```

### Pair

```c++
#include <utility>
using namespace std;
pair<string, int> p;
pair<string, int> p("haha", 5);
mp.insert(pair<string, int> ("haha", 5));
mp.insert(make_pair("haha", 5));
p.first = "haha"; p.second = 5;
```