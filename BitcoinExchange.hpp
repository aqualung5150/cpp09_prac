#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

template<typename T>
typename T::const_iterator greatest_less(T const &m, typename T::key_type const &k) {
    typename T::const_iterator it = m.upper_bound(k);
    if(it != m.begin()) {
        return --it;
    }
    return m.end();
}

template<typename T>
typename T::iterator greatest_less(T &m, typename T::key_type const &k) {
    typename T::iterator it = m.upper_bound(k);
    if(it != m.begin()) {
        return --it;
    }
    return m.end();
}

#endif