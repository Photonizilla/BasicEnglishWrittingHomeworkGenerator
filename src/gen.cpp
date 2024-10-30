#include <stdio.h>
#include <random>

inline void getLine(char* s);
inline void putLine(const char* s);
inline void copyLine(char* target, const char* s);
inline void Generate(int* permutation, const int n);
inline bool at_bin(const char* s);
inline void move_to_dir(char* dir, const char* s);

int main(int argc, char** argv) {
    
    if (!at_bin(argv[0])) {
        printf("Please run this program at location bin/.\n");
        return 0;
    }

    if (argc != 2) {
        printf("Error!\n");
        return 0;
    }

    int startWeek, endWeek;
    printf("Start week: ");
    scanf("%d", &startWeek);
    printf("  End week: ");
    scanf("%d", &endWeek);

    char dir[100] = "../backup/";
    move_to_dir(dir, argv[1]);
    freopen(dir, "r", stdin);

    char line[1000];
    char** originals = new char*[10000];
    char** translationsChn = new char*[10000];
    char** translationsEng = new char*[10000];
    int i, j, n;
    int permutation[10000];
    bool isChn = true;
    bool isOrg = true;
    
    n = 0;
    i = 0;
    j = 0;
    while (true) {
        getLine(line);
        if (line[0] == '%')
            break;
        if (line[0] == '\0')
            continue;
        if (isOrg) {
            isOrg = false;
            n++;
            originals[n] = new char[1000];
            copyLine(originals[n], line);
        } else if (isChn) {
            isChn = false;
            i++;
            translationsChn[i] = new char[1000];
            copyLine(translationsChn[i], line);
        } else {
            isOrg = true;
            isChn = true;
            j++;
            translationsEng[j] = new char[1000];
            copyLine(translationsEng[j], line);
        }
    }

    if (i != j || i != n) {
        printf("Error!\n");
        printf("originals = %d\ntranslationsChn = %d\ntranslationsEng = %d\n", n, i, j);
        return 0;
    }

    if (endWeek - startWeek + 1 > n) {
        printf("Database not large enough.\n%d weeks generated.", n);
    }

    Generate(permutation, n);

    freopen("../products/product.md", "w", stdout);
    printf("# Originals\n\n");
    int week = startWeek, day = 1;
    for (int k = 1; k <= n; k++) {
        if (k % 18 == 1) {
            if (week > endWeek) {
                break;
            }
            printf("## Week %d\n\n", week++);
            day = 1;
        }
        if (k % 3 == 1) {
            printf("### Day %d\n", day++);
        }
        putLine(originals[permutation[k]]);
        printf("\n");
        putLine(translationsChn[permutation[k]]);
        printf("\n");
        putLine(translationsEng[permutation[k]]);
        printf("\n");
    }

    delete[] originals;
    delete[] translationsChn;
    delete[] translationsEng;

    return 0;
}

inline void getLine(char* s) {
    int i = -1;
    do {
        scanf("%c", &s[++i]);
        if (s[i] == '`')
            i--;                    // ++++++++
    } while (s[i] != '\n');
    s[i] = '\0';
}

inline void putLine(const char* s) {
    printf("%s\n", s);
}

inline void copyLine(char* target, const char* s) {
    int i = 0;
    do {
        target[i] = s[i];
    } while (s[i++] != '\0');
}

inline void Generate(int* permutation, const int n) {
    bool taken[10000];
    for (int i = 1; i <= n; i++) {
        taken[i] = false;
    }
    std::random_device rd;
    std::mt19937 ran(rd());
    std::uniform_int_distribution<int> distr(1, n);
    for (int i = 1; i <= n; i++) {
        do {
            permutation[i] = distr(ran);
        } while (taken[permutation[i]]);
        taken[permutation[i]] = true;
    }
}

inline bool at_bin(const char* s) {
    char loc[] = "./gen";
    int i = 1;
    do {
        i++;
        if (s[i] != loc[i])
            return false;
    } while (s[i] != '\0');
    return true;
}

inline void move_to_dir(char* dir, const char* s) {
    int i = -1;
    do {
        i++;
        dir[i + 10] = s[i];
    } while (s[i] != '\0');
}

