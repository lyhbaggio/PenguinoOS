my class Iterator {
    # declared in BOOTSTRAP.pm
    #    is Iterable;          # parent class

    method iterator() { nqp::p6decont(self) }
}
