#include <stdio.h>

inline void getLine(char* s);
inline void putLine(const char* s);
inline void copyLine(char* target, const char* s);
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
	char line[1000];
	char** originals = new char*[10000];
	char** translationsChn = new char*[10000];
	char** translationsEng = new char*[10000];
	int i, j, n;
	bool isChn = true;
	bool isOrg = true;
	
	n = 0;
	i = 0;
	j = 0;

    char dir[100] = "../backup/";
    move_to_dir(dir, argv[1]);
	freopen(dir, "r", stdin);			// Those already in the library
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

	freopen("../markdown/libtranslation_add.md", "w", stdout);
	for (int k = 1; k <= n; k++) {
		putLine(originals[k]);
		putLine(translationsChn[k]);
		putLine(translationsEng[k]);
	}
	printf("%c\n", '%');

	delete[] originals;
	delete[] translationsChn;
	delete[] translationsEng;

	return 0;
}

inline void getLine(char* s) {
	int i = -1;
	do {
		scanf("%c", &s[++i]);
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

inline bool at_bin(const char* s) {
    char loc[] = "./restore_from";
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


