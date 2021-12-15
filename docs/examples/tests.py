import simple
import mixed
import hpyvarargs
import snippets


def test_simple_abs():
    assert simple.myabs(-42) == 42
    assert simple.myabs(42) == 42


def test_hpyvarargs():
    assert hpyvarargs.add_ints(40, 2) == 42


def test_mixed_add_ints():
    assert mixed.add_ints_legacy(40, 2) == 42
    assert mixed.add_ints(40, 2) == 42


def test_snippets():
    x = 2
    assert snippets.test_foo_and_is_same_object(x, x) == 1
    assert snippets.test_foo_and_is_same_object(x, 42) == 0
