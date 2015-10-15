LETTER     [A-Za-z]
SPACE      [" "\t]
LETTSPACE   ({LETTER}|{SPACE})
CONJUNCTION (and|or|but|And|Or|But|AND|OR|BUT)

%%

{LETTSPACE}*" "{CONJUNCTION}" "{LETTSPACE}*\n   printf("Compound Sentence\n");
{LETTSPACE}+\n                                  printf("Simple Sentence\n");
\n                                              printf("Error: Not a sentence\n");
.                                               ;

%%
