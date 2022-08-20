#ifndef __error_handler_hpp_
#define __error_handler_hpp_

#include <stdexcept>
#include <string>

namespace lacuna {
    enum ErrorType : int {
        RUNTIME=0, OUT_OF_RANGE=1, LOGIC=2, LENGTH=3, UNDERFLOW=4,
        DOMAIN=5, INVALID_ARGUMENT=6, RANGE=7, OVERFLOW=8
    };

    class ErrorHandler {
        public:

        static void Init();
        static void Destroy();

        static void ThrowError(std::string message, ErrorType type);
        private:
    };
}
#endif // __error_handler_hpp_