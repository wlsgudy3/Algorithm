const int MAX_N = 100005;
int money[MAX_N];
int UID[MAX_N];
int heap_size;
int result_temp[10][2];
int result_cnt;

#define parent (i >> 1)
#define left (i << 1)
#define right (i << 1 | 1)

void swap(int &a, int & b) { //이 부분 고치자
    int temp = a;
    a = b;
    b = temp;
}

void init()
{
    for (int i = 0; i < MAX_N; i++) {
        money[i] = -1;
        UID[i] = -1;
    }
    heap_size = 0;
}

void addUser(int uID, int income)
{
    money[++heap_size] = income;
    UID[heap_size] = uID;
    for (int i = heap_size; parent != 0; i >>= 1) {
        if (money[parent] < money[i]) {
            swap(money[parent], money[i]);
            swap(UID[parent], UID[i]);
        }
        else if (money[parent] == money[i]) {
            if (UID[parent] > UID[i]) {
                swap(money[parent], money[i]);
                swap(UID[parent], UID[i]);
            }
        }
        else
            break;
    }
}

int getTop() {
    int TopID = UID[1];
    result_temp[result_cnt][0] = UID[1];
    result_temp[result_cnt++][1] = money[1];
    money[1] = money[heap_size];
    UID[1] = UID[heap_size--];
    for (int i = 1; left <= heap_size;) {
        if (left == heap_size) { //left가 마지막 힙
            if (money[i] < money[left]) {
                swap(money[i], money[left]);
                swap(UID[i], UID[left]);
                i = left;
            }
            else if (money[i] == money[left]) {
                if (UID[i] > UID[left]) {
                    swap(money[i], money[left]);
                    swap(UID[i], UID[left]);
                    i = left;
                }
            }
            else
                break;
        }
        else if (money[left] > money[right]) {
            if (money[i] < money[left]) {
                swap(money[i], money[left]);
                swap(UID[i], UID[left]);
                i = left;
            }
            else if (money[i] == money[left]) {
                if (UID[i] > UID[left]) {
                    swap(money[i], money[left]);
                    swap(UID[i], UID[left]);
                    i = left;
                }
            }
            else
                break;
        }
        else if (money[left] < money[right]) {
            if (money[i] < money[right]) {
                swap(money[i], money[right]);
                swap(UID[i], UID[right]);
                i = right;
            }
            else if (money[i] == money[right]) {
                if (UID[i] > UID[right]) {
                    swap(money[i], money[right]);
                    swap(UID[i], UID[right]);
                    i = right;
                }
            }
            else
                break;
        }
        else if (money[left] == money[right]) {
            if (money[i] < money[left]) {
                if (UID[left] < UID[right]) {
                    swap(money[i], money[left]);
                    swap(UID[i], UID[left]);
                    i = left;
                }
                else {
                    swap(money[i], money[right]);
                    swap(UID[i], UID[right]);
                    i = right;
                }
            }
            else if (money[i] == money[left]) {
                if (UID[left] > UID[right]) {
                    if (UID[i] > UID[left]) {
                        swap(money[i], money[left]);
                        swap(UID[i], UID[left]);
                        i = left;
                    }
                }
                else {
                    if (UID[i] > UID[right]) {
                        swap(money[i], money[right]);
                        swap(UID[i], UID[right]);
                        i = right;
                    }
                }
            }
            else
                break;
        }
    }
    return TopID;
}

int getTop10(int* result)
{
    result_cnt = 0;
    if (heap_size <= 10) {
        int temp = heap_size;
        for (int i = 0; i < temp; i++) {
            result[i] = getTop();
        }
        for (int j = 0; j < result_cnt; j++) {
            addUser(result_temp[j][0], result_temp[j][1]);
        }
        return temp;
    }
    else {
        for (int i = 0; i < 10; i++) {
            result[i] = getTop();
        }
        for (int j = 0; j < 10; j++) {
            addUser(result_temp[j][0], result_temp[j][1]);
        }
        return 10;
    }
}

#undef parent
#undef left
#undef right