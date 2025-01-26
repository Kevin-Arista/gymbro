if we use double bracket notation: 
we must specify how many strings at most to be inside array, then how many chars can at most be inside each string
ex: char keys[4][6] = {"weigh", "calor", "journ", "exerc"};


RULE: you cannot initialize a array using a pointer!


Why did we decided to store our flag characters inside an array of strings and not an array of chars?
--> Once we've determined whether our arg is content, flag, or keyword: in the case it is flag formatted, we will check if it is a valid flag.
--> this permits us to throw "invalid flag error" or proceed to check for flag args (check if they are correct datatype too!)
