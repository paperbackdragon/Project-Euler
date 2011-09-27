--Examples from "Learn You A Haskell For Great Good"--

doubleMe x = x + x

doubleUs x y = doubleMe x + doubleMe y

doubleSmallNumber x = if x > 100 then x	else x*2
						
doubleSmallNumber' x = (if x > 100 then x else x*2) + 1

--left off at: "Guards, Guards!"--
