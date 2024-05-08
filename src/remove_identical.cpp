#include <stdio.h>

inline void getLine(char* s);
inline void putLine(const char* s);
inline void copyLine(char* target, const char* s);
inline bool repeated(char** list, const int n, const char* s);
inline bool at_bin(const char* s);

int main(int argc, char** argv) {
    
    if (!at_bin(argv[0])) {
        printf("Please run this program at location bin/.\n");
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

	freopen("../markdown/libtranslation_add.md", "r", stdin);			// Those already in the library
	while (true) {
		getLine(line);
		if (line[0] == '%')
			break;
		if (line[0] == '\0')
			continue;
		if (isOrg) {
			if (repeated(originals, n, line)) {
				getLine(line);
				getLine(line);
				continue;
			}
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

inline bool repeated(char** list, const int n, const char* s) {
	bool same;
	for (int i = 1; i <= n; i++) {
		int j = -1;
		same = true;
		do {
			j++;
			if (list[i][j] != s[j]) {
				same = false;
				break;
			}
		} while (list[i][j] != '\0' && s[j] != '\0');
		if (same) {
			return true;
		}
	}
	return false;
}

inline bool at_bin(const char* s) {
    char loc[] = "./remove_identical";
    int i = 1;
    do {
        i++;
        if (s[i] != loc[i])
            return false;
    } while (s[i] != '\0');
    return true;
}

