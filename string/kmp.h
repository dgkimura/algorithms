/* Fast Pattern Matching In Strings: Knuth-Morris-Pratt
 *
 * O(m+n) runtime complexity for substring m in string n.
 * O(m) space complexity.
 */

static int search(const char *, const char *);
