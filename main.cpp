#include "JSONlang.h"
JSON(hello)
PROGRAM_BEGIN

JSON(name1) = STRING("Aggelos")
JSON(name2) = STRING("Marselo")

PRINT name1
PRINT name2

JSON(oop) = OBJECT{ 
    KEY(title) : STRING("title"),
    KEY(title2) : STRING("title5")
} +OBJECT{ 
    KEY(title3) : STRING("title"),
    KEY(title2) : STRING("title")
}

PRINT oop


JSON(secondarray) = ARRAY[ STRING("Kalispera"), STRING("KALH")]
PRINT secondarray

SET secondarray APPEND STRING("KALHSPERAAAAA"),STRING("MISO LEPTO") 
PRINT secondarray

PRINT NUMBER(21)+NUMBER(22)
PRINT NUMBER(23)-NUMBER(21)

PRINT NUMBER(30.5)-NUMBER(0.5)
PRINT NUMBER(50)*NUMBER(2)
PRINT NUMBER(30)/NUMBER(2)

JSON(UOC) = OBJECT {
    KEY(MATHIMATIKO) : OBJECT {
        KEY(MEM341) : STRING("Oikonomia or sumn"),
        KEY(MEM555) : STRING("Kati me arithmous"),
        KEY(MEM666) : STRING("Arithmoi 2")
    },
    KEY(CSD) : OBJECT {
        KEY(HY100) : STRING("Eisagwgh"),
        KEY(HY352) : STRING("software engineering"),
        KEY(HY469) : STRING("HCI")
    },
    KEY(IATRIKI) : OBJECT {
        KEY(MED1000) : STRING("Eisagwgh sto depon"),
        KEY(MED252) : STRING("Antikeimenostrafhs farmakologia"),
        KEY(MED352) : STRING("Mixanikos Swmatos"),
        KEY(MED240) : STRING("Domes tis kardias"),
        KEY(MED359) : STRING("Web tis anw koilias"),
        KEY(MED340) : STRING("")
    }
    
}
PRINT UOC

ERASE UOC["MATHIMATIKO"]
ERASE UOC["CSD"]
PRINT STRING("Hello")+STRING(" World")
PRINT UOC
PRINT STRING("Hello")+STRING(" Mars")
 
SET UOC["IATRIKI"]["MED340"] ASSIGN STRING("GLWSSES KAI VOCAL CORDS")
SET UOC["IATRIKI"]["MED458"] ASSIGN STRING("Eisagwsh sthn rivosomato-kryptologia")
PRINT UOC


JSON(thirdarray) = ARRAY[ NUMBER(20), NUMBER(21)]

PRINT STRING("APPENDING NUMBERS TO ARRAY")

SET thirdarray APPEND NUMBER(25)
SET thirdarray APPEND NUMBER(26)
PRINT thirdarray

JSON(hy352_nik) = OBJECT{ KEY(exam):NUMBER(7), KEY(project):NUMBER(8) }
JSON(students) = ARRAY [
    OBJECT{
        KEY(name) : STRING("Nikos ") + STRING("Nikolaou"),
        KEY(id) : NUMBER(4444),
        KEY(grades) : ARRAY[
            OBJECT {
                KEY(hy352): hy352_nik["exam"] * NUMBER(0.75) + hy352_nik["project"] * NUMBER(0.25)
            }]
        }
]

PRINT students

JSON(book) = OBJECT {
    KEY(title) : STRING("Gone Girl"),
    KEY(published) : NUMBER(2012),
    KEY(type) : STRING("Thriller"),
    KEY(author) : OBJECT{
        KEY(firstname) : STRING("GILLIAN"),
        KEY(sirname) : STRING("FLYNN"),
        KEY(age) : NUMBER(45)
    }
}
PRINT book
JSON(help) = ARRAY[NUMBER(20)>NUMBER(21)]
PRINT help

PRINT (NUMBER(20)>NUMBER(21))
PRINT (NUMBER(20)!=NUMBER(25))
PRINT (NUMBER(20)!=NUMBER(20))
PRINT (NUMBER(25)==NUMBER(25))
PRINT (!FALSE)

PRINT TYPE_OF(help)
PRINT TYPE_OF(book)
PRINT TYPE_OF(NUMBER(23))
PRINT TYPE_OF(STRING("HY352"))
PRINT TYPE_OF(NUMBER(23)+NUMBER(25))

PRINT HAS_KEY(book,"title")

PRINT IS_EMPTY(help)
PRINT IS_EMPTY(book)
PRINT IS_EMPTY(NUMBER(23))
PRINT SIZE_OF(help)
PRINT SIZE_OF(book)

JSON(students2) = ARRAY [
    OBJECT{
        KEY(name) : STRING("Nikos ") + STRING("Nikolaou"),
        KEY(id) : NUMBER(4444),
        KEY(grades) : ARRAY[
            OBJECT {
                KEY(hy352): hy352_nik["exam"] * NUMBER(0.75) + hy352_nik["project"] * NUMBER(0.25)
            }]
        }
]
ERASE name1
PROGRAM_END