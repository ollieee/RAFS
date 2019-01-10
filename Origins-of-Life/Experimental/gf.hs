-- Gf algorithm in Haskell

type X = Int               -- Molecule tytype R = Set X -> X -> Set X -- Reaction type (represented as a function)
type R = [X] -> X -> Set X -- Reaction type (represented as a function)

closure :: [X] -> [X]
closure fs rs = fixedPoint (\xs -> applyReactions xs rs) fs

fixedPoint :: Eq a => (a -> a) -> a -> a
fixedPoint f arg =
  case (f arg == arg) of
    True -> arg
    False -> fixedPoint f (f arg)

psi :: Eq t1 => (t1 -> t2) -> ([t1] -> t3) -> (t2 -> t3 -> Bool) -> [t1] -> [t1]
psi g f leq sA = filter (\y -> leq (g y) (f sA)) sA;;

psi' :: Eq t1 => (t1 -> t2) -> ([t1] -> t3) -> (t2 -> t3 -> Bool) -> [t1] -> [t1]
psi' g f leq = fixedPoint (psi g f leq)
