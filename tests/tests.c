#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "../src/tinyprintf.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

/* ===== BASIC ===== */

Test(tinyprintf, hello_world, .init = redirect_all_stdout)
{
    int n = tinyprintf("Hello World!");
    fflush(stdout);
    cr_expect_stdout_eq_str("Hello World!");
    cr_expect_eq(n, 12);
}

Test(tinyprintf, empty, .init = redirect_all_stdout)
{
    int n = tinyprintf("");
    fflush(stdout);
    cr_expect_stdout_eq_str("");
    cr_expect_eq(n, 0);
}

/* ===== CHAR ===== */

Test(tinyprintf, char_simple, .init = redirect_all_stdout)
{
    int n = tinyprintf("%c", 'A');
    fflush(stdout);
    cr_expect_stdout_eq_str("A");
    cr_expect_eq(n, 1);
}

Test(tinyprintf, char_multiple, .init = redirect_all_stdout)
{
    int n = tinyprintf("%c %c %c", 'A', 'B', 'C');
    fflush(stdout);
    cr_expect_stdout_eq_str("A B C");
    cr_expect_eq(n, 5);
}

/* ===== STRING ===== */

Test(tinyprintf, string_basic, .init = redirect_all_stdout)
{
    int n = tinyprintf("%s", "hello");
    fflush(stdout);
    cr_expect_stdout_eq_str("hello");
    cr_expect_eq(n, 5);
}

Test(tinyprintf, string_null, .init = redirect_all_stdout)
{
    int n = tinyprintf("%s", NULL);
    fflush(stdout);
    cr_expect_stdout_eq_str("(null)");
    cr_expect_eq(n, 6);
}

/* ===== SIGNED ===== */

Test(tinyprintf, int_positive, .init = redirect_all_stdout)
{
    int n = tinyprintf("%d", 42);
    fflush(stdout);
    cr_expect_stdout_eq_str("42");
    cr_expect_eq(n, 2);
}

Test(tinyprintf, int_negative, .init = redirect_all_stdout)
{
    int n = tinyprintf("%d", -42);
    fflush(stdout);
    cr_expect_stdout_eq_str("-42");
    cr_expect_eq(n, 3);
}

Test(tinyprintf, int_zero, .init = redirect_all_stdout)
{
    int n = tinyprintf("%d", 0);
    fflush(stdout);
    cr_expect_stdout_eq_str("0");
    cr_expect_eq(n, 1);
}

/* ===== UNSIGNED ===== */

Test(tinyprintf, unsigned_basic, .init = redirect_all_stdout)
{
    int n = tinyprintf("%u", 123);
    fflush(stdout);
    cr_expect_stdout_eq_str("123");
    cr_expect_eq(n, 3);
}

Test(tinyprintf, unsigned_zero, .init = redirect_all_stdout)
{
    int n = tinyprintf("%u", 0);
    fflush(stdout);
    cr_expect_stdout_eq_str("0");
    cr_expect_eq(n, 1);
}

/* ===== HEX ===== */

Test(tinyprintf, hex_basic, .init = redirect_all_stdout)
{
    int n = tinyprintf("%x", 42);
    fflush(stdout);
    cr_expect_stdout_eq_str("2a");
    cr_expect_eq(n, 2);
}

Test(tinyprintf, hex_zero, .init = redirect_all_stdout)
{
    int n = tinyprintf("%x", 0);
    fflush(stdout);
    cr_expect_stdout_eq_str("0");
    cr_expect_eq(n, 1);
}

/* ===== OCTAL ===== */

Test(tinyprintf, octal_basic, .init = redirect_all_stdout)
{
    int n = tinyprintf("%o", 64);
    fflush(stdout);
    cr_expect_stdout_eq_str("100");
    cr_expect_eq(n, 3);
}

Test(tinyprintf, octal_zero, .init = redirect_all_stdout)
{
    int n = tinyprintf("%o", 0);
    fflush(stdout);
    cr_expect_stdout_eq_str("0");
    cr_expect_eq(n, 1);
}

/* ===== PERCENT ===== */

Test(tinyprintf, percent, .init = redirect_all_stdout)
{
    int n = tinyprintf("%%");
    fflush(stdout);
    cr_expect_stdout_eq_str("%");
    cr_expect_eq(n, 1);
}

/* ===== MIX ===== */

Test(tinyprintf, mixed1, .init = redirect_all_stdout)
{
    int n = tinyprintf("%s %d", "hello", 42);
    fflush(stdout);
    cr_expect_stdout_eq_str("hello 42");
    cr_expect_eq(n, 8);
}

Test(tinyprintf, mixed2, .init = redirect_all_stdout)
{
    int n = tinyprintf("%c %s %d %x", 'A', "test", 10, 10);
    fflush(stdout);
    cr_expect_stdout_eq_str("A test 10 a");
    cr_expect_eq(n, 11);
}

Test(tinyprintf, mixed3, .init = redirect_all_stdout)
{
    int n = tinyprintf("Hello [%x] %s", 42, "world!");
    fflush(stdout);
    cr_expect_stdout_eq_str("Hello [2a] world!");
    cr_expect_eq(n, 17);
}

/* ===== EDGE ===== */

Test(tinyprintf, long_number, .init = redirect_all_stdout)
{
    int n = tinyprintf("%d", 123456789);
    fflush(stdout);
    cr_expect_stdout_eq_str("123456789");
    cr_expect_eq(n, 9);
}

Test(tinyprintf, multiple_formats, .init = redirect_all_stdout)
{
    int n = tinyprintf("%d%d%d", 1, 2, 3);
    fflush(stdout);
    cr_expect_stdout_eq_str("123");
    cr_expect_eq(n, 3);
}

/* ===== UNKNOWN ===== */

Test(tinyprintf, unknown_format, .init = redirect_all_stdout)
{
    int n = tinyprintf("%t");
    fflush(stdout);
    cr_expect_stdout_eq_str("%t");
    cr_expect_eq(n, 2);
}
