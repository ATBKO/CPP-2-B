<div dir="rtl" lang="he">

# מלחמה
במטלה זו נממש את משחק הקלפים מלחמה עבור שני שחקנים. 
יש חפיסת קלפים רגיל עם 52 קלפים בתחילת המשחק החפיסה מעורבבת (בצורה ראנדומאלית) ומחולקת שווה בשווה בין שני השחקנים.
בכל תור השחקנים שולפים קלף אחד מראש הערימה שלהם השחקן עם הקלף הגבוהה ביותר לוקח את שני הקלפים אליו (2 מנצח אס).
אם השחקנים שלפו שני קלפים זהים אז הם מניחים קלף אחד הפוך ומעליו קלף פחות. השחק עם הקלף הגבוהה לוקח את כל ששת הקלפים. במידה ושוב יש תיקו ממשיכים עם קלף סגור ואחריו קלף פתוח עד שאחד השחקנים מנצח. התור נמשך עד שאחד השחקנים לוקח את הקופה או שנגמרים הקלפים. 
אם נגמרים הקלפים תוך כדי השובר שיוויון כל שחקן לוקח את הקלפים שהוא זרק (מתחלקים בקופה חצי חצי).
המשחק נמשך עד שנגמרים לשחקנים הקלפים והמנצח הוא השחקן שלקח לעצמו את מירב הקלפים. 

דוגמאות לפעולת המחלקה ניתן למצוא ב-[Demo.cpp](Demo.cpp).

בשלב ב עליכם לכתוב את המימוש המלא. מותר לערוך את המימוש של שלב א אבל אם עשיתם עבודה טובה לא יהיה בכך צורך.
יעלו טסטים נבחרים של סטודנטים. עליכם לעבור את כל הטסטים בציון 100. המטלה תיבדר ע"י הרצת

כיתבו את כל הקבצים הדרושים כך שהפקודות הבאות יעבדו ללא שגיאות:

<div dir='ltr'>

    bash grade

</div>


שימו לב:
אין לשנות קבצים קיימים, אלא רק להוסיף קבצים חדשים.
מערכת הבדיקה האוטומטית מעתיקה מחדש את כל הקבצים הקיימים על-גבי הפתרון שאתם מגישים,
ולכן כל שינוי שתעשו בקבצים הקיימים יימחק.

בהצלחה
</div>


## Test Verification:

```python
your commit is: 53bcedf

cloning your git: https://github.com/ATBKO/CPP-2-B.git

running:  git clone https://github.com/ATBKO/CPP-2-B.git


changing folder to: CPP-2-B
checking out you commit: 53bcedf

running:  git checkout 53bcedf


running:  bash grade
--- 0 seconds


### Cleaning old files (to prevent this, export DEBUG=1) ###
rm -f objects/card.o objects/game.o objects/player.o *.o test* demo*


### Check 1: all tests should pass
! make -f Makefile test1
clang++-14 -std=c++2a -Werror -Wsign-conversion -Isources --compile TestRunner.cpp -o TestRunner.o
clang++-14 -std=c++2a -Werror -Wsign-conversion -Isources --compile StudentTest1.cpp -o StudentTest1.o
clang++-14 -std=c++2a -Werror -Wsign-conversion -Isources --compile sources/card.cpp -o objects/card.o
clang++-14 -std=c++2a -Werror -Wsign-conversion -Isources --compile sources/game.cpp -o objects/game.o
clang++-14 -std=c++2a -Werror -Wsign-conversion -Isources --compile sources/player.cpp -o objects/player.o
clang++-14 -std=c++2a -Werror -Wsign-conversion -Isources TestRunner.o StudentTest1.o objects/card.o objects/game.o objects/player.o -o test1
! timeout 20 ./test1
[doctest] doctest version is "2.4.11"
[doctest] run with "--help" for options
Alice Played Ace of Diamonds Bob Played 4 of Clubs. Alice Wins
Alice Played 4 of Diamonds Bob Played 3 of Spades. Alice Wins
Alice Played King of Clubs Bob Played Jack of Clubs. Alice Wins
Alice Played 6 of Diamonds Bob Played Queen of Diamonds. Bob Wins
Alice Played 7 of Diamonds Bob Played 5 of Spades. Alice Wins
Alice Played Ace of Diamonds Bob Played 4 of Clubs. Alice Wins

Alice:
Win rate: 80%
Cards won: 8

Bob:
Win rate: 20%
Cards won: 2

Draw rate: 0%
Amount of draws: 0
Tie!
Bob
===============================================================================
[doctest] test cases:  8 |  8 passed | 0 failed | 0 skipped
[doctest] assertions: 21 | 21 passed | 0 failed |
[doctest] Status: SUCCESS!
--- 5 seconds
### Score 1: 100


### Check 2: clang-tidy should run without warnings in user code
! timeout 20 make -f Makefile tidy
clang-tidy sources/card.hpp sources/game.hpp sources/player.hpp -extra-arg=-std=c++2a -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=* --
13261 warnings generated.
27827 warnings generated.
42663 warnings generated.
Suppressed 42663 warnings (42663 in non-user code).
Use -header-filter=.* to display errors from all non-system headers. Use -system-headers to display errors from system headers as well.
--- 11 seconds
### Score 2: 100


### Check 3: valgrind should run without errors
! timeout 20 make -f Makefile valgrind
valgrind --tool=memcheck -v --leak-check=full --show-leak-kinds=all  --error-exitcode=99 ./test1 2>&1 | { egrep "lost| at " || true; }
==13988==     in use at exit: 0 bytes in 0 blocks
--- 13 seconds
### Score 3: 100


Grade: 100


```
