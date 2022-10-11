import MyNat.Definition
namespace MyNat
open MyNat
/-!
# Advanced proposition world.

## Level 10: the law of the excluded middle.

We proved earlier that `(P → Q) → (¬ Q → ¬ P)`. The converse,
that `(¬ Q → ¬ P) → (P → Q)` is certainly true, but trying to prove
it using what we've learnt so far is impossible (because it is not provable in
constructive logic). For example, after

```
intro h
intro p
repeat rw [not_iff_imp_false] at h
```

in the below, you are left with
```
P Q : Prop,
h : (Q → false) → P → false
p : P
⊢ Q
```

The tools you have are not sufficient to continue. But you can just
prove this, and any other basic lemmas of this form like `¬ ¬ P → P`,
using the `by_cases` tactic. Instead of starting with all the `intro`s,
try this instead:

`by_cases p : P; by_cases q : Q`

**Note the semicolon**! It means "do the next tactic to all the goals, not just the top one".
After it, there are four goals, one for each of the four possibilities PQ=TT, TF, FT, FF.
You can see that `p` is a proof of `P` in some of the goals, and a proof of `¬ P` in others.
Similar comments apply to `q`.

`repeat cc` then finishes the job.

This approach assumed that `P ∨ ¬ P` was true; the `by_cases` tactic just does `cases` on
this result. This is called the law of the excluded middle, and it cannot be proved just
using tactics such as `intro` and `apply`.

## Lemma
If `P` and `Q` are true/false statements, then
`(¬ Q ⟹ ¬ P) ⟹ (P ⟹ Q).`
-/
-- lemma contrapositive2 (P Q : Prop) : (¬ Q → ¬ P) → (P → Q) := by
--   by_cases p : P
--   by_cases q : Q
--   repeat cc


/-!
OK that's enough logic -- now perhaps it's time to go on to Advanced Addition World!
-/


/-!
## Pro tip

In fact the tactic `tauto!` just kills this goal (and many other logic goals) immediately.


## Tactic : by_cases

## Summary

`by_cases h : P` does a cases split on whether `P` is true or false.

## Details

Some logic goals cannot be proved with `intro` and `apply` and `exact`.
The simplest example is the law of the excluded middle `¬ ¬ P → P`.
You can prove this using truth tables but not with `intro`, `apply` etc.
To do a truth table proof, the tactic `by_cases h : P` will turn a goal of
`⊢ ¬ ¬ P → P` into two goals

```
P : Prop,
h : P
⊢ ¬¬P → P

P : Prop,
h : ¬P
⊢ ¬¬P → P
```

Each of these can now be proved using `intro`, `apply`, `exact` and `exfalso`.
Remember though that in these simple logic cases, high-powered logic
tactics like `cc` and `tauto!` will just prove everything.



## Tactic : tauto

## Summary

The `tauto` tactic (and its variant `tauto!`) will close various logic
goals.

## Details

`tauto` is an all-purpose logic tactic which will try to solve goals using pure
logical reasoning -- for example it will close the following goal:

```
P Q : Prop,
hP : P,
hQ : Q
⊢ P ∧ Q
```

`tauto` is supposed to only use constructive logic, but its big brother `tauto!` uses classical logic
and hence closes more goals.
-/
