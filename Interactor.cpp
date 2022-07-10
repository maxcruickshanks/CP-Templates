#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int, int> pi;
namespace Printer {
    FILE *stream = stdout;

    void set_stream(FILE *st) { stream = st; }

    void print_impl(int x) { fprintf(stream, "%d", x); }
    void print_impl(ll x) { fprintf(stream, "%lld", x); }
    void print_impl(size_t x) { fprintf(stream, "%llu", x); }
    void print_impl(const char *x) { fprintf(stream, "%s", x); }
    void print_impl(const string &x) { print_impl(x.c_str()); }
    void print_impl(char x) { fprintf(stream, "%c", x); }

    template <typename A, typename B> void print_impl(const pair<A, B> &p) {
        print_impl(p.first);

        print_impl(' ');

        print_impl(p.second);
    }

    template <typename T, size_t... I>
    void print_tuple(const T &t, index_sequence<I...>) {
        (..., (print_impl(I == 0 ? "" : " "), print_impl(get<I>(t))));
    }

    template <typename... Ts> void print_impl(const tuple<Ts...> &a) {
        print_tuple(a, std::make_index_sequence<sizeof...(Ts)>());
    }

    void print_many() {}

    template <typename T> void print_many(const T &arg) { print_impl(arg); }

    template <typename T, typename... Ts>
    void print_many(const T &arg, Ts &&... args) {
        print_impl(arg);
        print_impl(' ');
        print_many(forward<Ts...>(args...));
    }

    void print() { fprintf(stream, "\n"); }

    template <typename... Ts> void print(Ts &&... args) {
        print_many(forward<Ts...>(args...));

        print();
    }
}; // namespace Printer

using Printer::print;
using Printer::set_stream;

// modified from a template by wleung_bvg

namespace Reader {
    const int ERROR_COUNT = 4;

    enum error_type { OUT_OF_RANGE = 0, INVALID_ARGUMENT, WRONG_WHITESPACE };

    const char *error_names[ERROR_COUNT] = {"OUT_OF_RANGE", "INVALID_ARGUMENT",
                                            "WRONG_WHITESPACE"};

    class FileReader {

    private:
        FILE *stream;

        bool hasLast;
        char lastChar;

    public:
        FileReader(FILE *f) : stream(f), hasLast(false), lastChar(0) {}

        FileReader(char *path) : FileReader(fopen(path, "r")) {}

        virtual void __attribute__((noreturn)) errorHandler(error_type e) = 0;

        char peekChar() {
            if (!hasLast) {
                lastChar = getc(stream);
                hasLast = true;
            }
            return lastChar;
        }

        char readChar() {
            char ret = peekChar();
            hasLast = false;
            return ret;
        }

        bool eof() { return peekChar() == char_traits<char>::eof(); }

        void trim() {
            while (isspace(peekChar()) && !eof()) {
                readChar();
            }
        }

        ll readInt() {
            string token = "";
            while (isdigit(peekChar()) || peekChar() == '-')
                token.push_back(readChar());
            try {
                ll ret = stoll(token);

                return ret;
            } catch (const out_of_range &e) {
                errorHandler(OUT_OF_RANGE);
            } catch (const invalid_argument &e) {
                errorHandler(INVALID_ARGUMENT);
            }
        }

        string readFile() {
            string ret = "";
            while (!eof()) {
                ret.push_back(readChar());
            }

            readEOF();

            return ret;
        }

        string readString(int N) {
            string ret = "";
            for (int i = 0; i < N; i++) {
                ret.push_back(readChar());
            }

            return ret;
        }

        string readLine() {
            string ret = "";
            while (peekChar() != '\n' && !eof())
                ret.push_back(readChar());
            readNewLine();

            return ret;
        }

        void readSpace() {
            if (readChar() != ' ')
                errorHandler(WRONG_WHITESPACE);
        }

        void readNewLine() {
            if (readChar() != '\n')
                errorHandler(WRONG_WHITESPACE);
        }

        void readEOF() {
            if (!eof())
                errorHandler(WRONG_WHITESPACE);
        }

        string readToken() {
            string token = "";

            while (!isspace(peekChar()) && !eof())
                token.push_back(readChar());

            return token;
        }

    private:
        template <typename Arr> void _fill_arr(Arr &a, size_t N) {
            for (int i = 0; i < N; i++) {
                if (i)
                    readSpace();
                a[i] = readInt();
            }
            readNewLine();
        }

    public:
        template <size_t length, typename T = ll> array<T, length> readIntTuple() {
            array<T, length> res;
            _fill_arr(res, length);
            return res;
        }

        template <typename T = ll> vector<T> readIntArray(size_t N) {
            vector<T> v;
            v.resize(N);
            _fill_arr(v, N);
            return v;
        }

        template <typename T, typename... Ts> void readInts(T &arg, Ts &&... args) {
            arg = readInt();
            readSpace();
            readInts(args...);
        }

        template <typename T> void readInts(T &arg) {
            readIntArg(arg);
            readNewLine();
        }
    };

    class ValidatingReader : public FileReader {
        using FileReader::FileReader;

        void __attribute__((noreturn)) errorHandler(error_type e) {
            if (e >= ERROR_COUNT)
                throw runtime_error("Unknown error in FileReader");

            throw runtime_error(error_names[e]);
        }
    };
} // namespace Reader

using Reader::ValidatingReader;

namespace CheckerCodes {
    int AC = 0;
    int WA = 1;
    int PE = 2;
    int IE = 3;
    int PARTIAL = 7;
} // namespace CheckerCodes

const ll MAX = 1e18;

class CheckerReader : public Reader::FileReader {
    using FileReader::FileReader;

    void __attribute__((noreturn)) errorHandler(enum Reader::error_type e) {
        print(MAX + 1);
        switch (e) {
            case Reader::error_type::OUT_OF_RANGE:
                exit(CheckerCodes::WA);

            case Reader::error_type::INVALID_ARGUMENT:
            case Reader::error_type::WRONG_WHITESPACE:
                exit(CheckerCodes::PE);

            default:
                exit(CheckerCodes::IE);
        }
    }
};
void assertWA(bool cond) {
    if (!cond) {
        exit(CheckerCodes::WA);
    }
}

int main(int argc, char **argv) {
    CheckerReader prog_r(stdin);
    ValidatingReader in_r(argv[1]);

    return CheckerCodes::IE;
}
