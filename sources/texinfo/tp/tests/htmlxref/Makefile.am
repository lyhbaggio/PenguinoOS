EXTRA_DIST = htmlxref.cnf-ref \
 tests-parser.txt res_parser

DISTCLEANFILES = tests.log tests.out htmlxref.cnf

distclean-local:
	rm -rf out_parser diffs

dist-hook:
	rm -rf `find $(distdir)/res_parser -name CVS`
