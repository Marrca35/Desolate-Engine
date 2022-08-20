#ifndef __error_handler_hpp_
#define __error_handler_hpp

#include <stdexcept>

namespace lacuna {
    class ErrorHandler {
        public:
        ErrorHandler() { }

        void Init();
        void Destroy();
        private:
    };
}
#endif // __error_handler_hpp_