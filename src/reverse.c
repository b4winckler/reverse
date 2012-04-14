#include <R.h>
#include <Rdefines.h>

/* Take an int vector and reverse it. */
SEXP reverse(SEXP x)
{
    PROTECT(x = AS_INTEGER(x));
    int n = GET_LENGTH(x);
    if (n <= 0) {
        UNPROTECT(1);
        return R_NilValue;
    }

    SEXP y;
    PROTECT(y = NEW_INTEGER(n));

    const int *px = INTEGER_POINTER(x);
    int *py = INTEGER_POINTER(y) + n - 1;
    for (int i = 0; i < n; ++i)
        *py-- = *px++;

    UNPROTECT(2);

    return y;
}
