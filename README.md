# BasicEnglishWrittingHomeworkGenerator
Generates the translation homework from a database.

## Introduction on the files
- `Originals.md` and `Translations.md` are original materials, they are combined into `Library.md`.
- In the directory `markdown/`, `libtranslation_add.md` is used as the database, `libtranslation.md` is used as a main backup, `libtranslation copy.md` is a double backup.
- In the directory `products/`, `productOriginals.md` and `productTranslations.md` are (obviously) products.

## Usage
1. `./generator` generates the products with the database `libtranslation_add.md`.
2. `./generate_from <filename>` generates the products with database `backup/<filename>` (say we may write `./generate_from backup1.md`).
3. `./add_to_lib` adds things in `AddToLibrary/add_to_lib.md` to the end of `markdown/libtranslation_add.md`. **Make sure `add_to_lib.md` is end with a line that includes the only character `%`!**
4. `./remove_identical` removes identical sentences in `markdown/libtranslation_add.md`.
5. `./backup_to <filename>` makes a backup of `markdown/libtranslation_add.md` to `backup/<filename>`.
6. `./backup_lib` makes a backup of `markdown/libtranslation_add.md` to `markdown/libtranslation.md`.
7. `./restore_from <filename>` restores a backup `backup/<filename>` to `markdown/libtranslation_add.md`.
8. `./restore_lib` restores `markdown/libtranslation.md` to `markdown/libtranslation_add.md`.

Note that `generate_from`, `backup_to` and `restore_from` deal with files in `backup/`, while the other programs deal with files in `markdown/`. No program can modify `markdown/libtranslation_copy.md`.
