#include "ErrorHandler.hpp"

namespace lacuna {
    void ErrorHandler::Init() {

    }

    void ErrorHandler::Destroy() {

    }

    void ErrorHandler::ThrowError(std::string message, ErrorType type) {
        switch(type) {
            case ErrorType::RUNTIME:
                {
                    throw std::runtime_error(message);
                    break;
                }
            case ErrorType::DOMAIN:
                {
                    throw std::domain_error(message);
                    break;
                }
            case ErrorType::INVALID_ARGUMENT:
                {
                    throw std::invalid_argument(message);
                    break;
                }
            case ErrorType::LENGTH:
                {
                    throw std::length_error(message);
                    break;
                }
            case ErrorType::LOGIC:
                {
                    throw std::logic_error(message);
                    break;
                }
            case ErrorType::OUT_OF_RANGE:
                {
                    throw std::out_of_range(message);
                    break;
                }
            case ErrorType::OVERFLOW:
                {
                    throw std::overflow_error(message);
                    break;
                }
            case ErrorType::RANGE:
                {
                    throw std::range_error(message);
                    break;
                }
            case ErrorType::UNDERFLOW:
                {
                    throw std::underflow_error(message);
                    break;
                }
        }
    }
}