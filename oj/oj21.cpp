#include <bits/stdc++.h>

int countDeafRats(const std::string &town)
{
    int count = 0;
    int i = 0;
    while (town[i] != 'P') {
        switch (town[i]){
            case 'O': count++;
            case '~': i++;
            default : i++;
        }
    }
    i++;
    while (i < town.size()) {
        switch (town[i]){
            case '~': count++;
            case 'O': i++;
            default : i++;
        }
    }
    return count;
}