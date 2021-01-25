#pragma once

#include <istream>
#include <ostream>

#include <vector>

template <typename T> using Vec = std::vector<T>;

namespace std {

template <typename T>
std::ostream &operator<<(std::ostream &os, const Vec<T> &) {
  return os;
}

template <typename T> std::istream &operator>>(std::istream &is, Vec<T> &) {
  return is;
}
} // namespace std

// DBus Serialisation
struct DBusMessageIter;

template <typename T>
DBusMessageIter &operator<<(DBusMessageIter &os, const Vec<T> &);

template <typename T>
DBusMessageIter &operator>>(DBusMessageIter &is, Vec<T> &);