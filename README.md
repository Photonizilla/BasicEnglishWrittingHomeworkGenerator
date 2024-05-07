# BasicEnglishWrittingHomeworkGenerator
Generates the translation homework from a database.

## Introduction on the files
- `Originals.md` and `Translations.md` are original materials, they are combined into `Library.md`.
- `libtranslation_add.md` is used as the database, `libtranslation.md` is used as a main backup, `libtranslation copy.md` is a double backup.
- `productOriginals.md` and `productTranslations.md` are (obviously) products.

## Usage
1. `./generate_from <filename>` generates the products with database `<filename>` (say we may write `./generate_from libtranslation_add.md`).
2. `./generator` generates the products with the database `libtranslation_add.md`.
3. `./add_to_lib` adds things in `add_to_lib.md` to the end of `libtranslation_add.md`. **Make sure `add_to_lib.md` is end with a line that includes the only character `%`!**
4. `./remove_identical` removes identical sentences in `libtranslation_add.md`.
5. `./backup_to <filename>` make a backup of `libtranslation_add.md` named `<filename>`.
6. `./restore_from <filename>` restores a backup named `<filename>` to `libtranslation_add.md`.
7. `./restore_lib` restores `libtranslation.md` to `libtranslation_add.md`.
