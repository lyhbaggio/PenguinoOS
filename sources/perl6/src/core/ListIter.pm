my class List { ... }

my class ListIter {
    # Attributes defined in BOOTSTRAP.pm:
    #   has $!reified;         # return value for already-reified iterator
    #   has $!nextiter;        # next iterator in sequence, if any
    #   has Mu $!rest;         # RPA of elements remaining to be reified
    #   has $!list;            # List object associated with this iterator
    
    method reify($n = 1) {
        unless nqp::isconcrete($!reified) {
            my $eager = nqp::p6bool(nqp::istype($n, Whatever));
            my $flattens = nqp::p6bool(nqp::isconcrete($!list)) && $!list.flattens;
            my int $count = $eager
                ?? 100000
                !! nqp::unbox_i(nqp::istype($n, Int) ?? $n !! $n.Int);
            my $rpa := nqp::list();
            my Mu $x;
            my int $index;
            my $want_types := $flattens
                ?? nqp::list(Iterable, Parcel)
                !! nqp::list(Iterable);
            pir::perl6_shiftpush__0PPI($rpa, $!rest, nqp::elems($!rest))
                if nqp::istype($!list, LoL);
            while $!rest && (nqp::elems($rpa) < $count) {
                $index = pir::perl6_rpa_find_types__IPPii(
                                 $!rest, $want_types, 0, $count);
                pir::perl6_shiftpush__0PPi($rpa, $!rest, $index);
                if $!rest && (nqp::elems($rpa) < $count) {
                    $x := nqp::shift($!rest);
                    if nqp::isconcrete($x) {
                        (nqp::unshift($!rest, $x); last) if $eager && $x.infinite;
                        $x := $x.iterator.reify(
                                  $eager 
                                    ?? Whatever 
                                    !! nqp::p6box_i($count - nqp::elems($rpa)))
                            if nqp::istype($x, Iterable);
                        nqp::splice($!rest, nqp::getattr($x, Parcel, '$!storage'), 0, 0);
                    
                    }
                    elsif nqp::not_i(nqp::istype($x, Nil)) {
                        nqp::push($rpa, $x);
                    }
                }
            }
            my $reified := nqp::p6parcel($rpa, Any);
            nqp::bindattr(self, ListIter, '$!nextiter', nqp::p6listiter($!rest, $!list))
                if $!rest;
            $reified := $!list.REIFY($reified, $!nextiter) if nqp::isconcrete($!list);
            nqp::push( nqp::getattr($reified, Parcel, '$!storage'), $!nextiter)
                if $!rest;
            nqp::bindattr(self, ListIter, '$!reified', $reified);
            # free up $!list and $!rest
            nqp::bindattr(self, ListIter, '$!list', Mu);
            nqp::bindattr(self, ListIter, '$!rest', Mu);
        }
        $!reified;
    }

    method infinite() {
        $!rest 
          ?? nqp::istype(nqp::atpos($!rest, 0), Iterable)
             && nqp::atpos($!rest,0).infinite
             || Mu
          !! Bool::False
    }

    method iterator() { self }
    method nextiter() { $!nextiter }

    multi method DUMP(ListIter:D:) {
        self.DUMP-ID() ~ '('
          ~ ("\x221e " if self.infinite) ~
          ~ ':reified('  ~ DUMP($!reified) ~ '), '
          ~ ':rest('     ~ DUMP($!rest) ~ '), '
          ~ ':list('     ~ $!list.DUMP-ID() ~ ')'
          ~ ')'
    }
         
}


