#ifndef YOGI_API_EXCEPTIONT_HPP
#define YOGI_API_EXCEPTIONT_HPP

#include "../config.h"
#include "Exception.hpp"


namespace yogi {
namespace api {

/***************************************************************************//**
 * Template class for exceptions
 *
 * @tparam TE Error code
 ******************************************************************************/
template <Exception::error_code_type TE>
class ExceptionT final : public Exception
{
public:
    ExceptionT()
        : Exception{TE}
    {
    }

    static Exception register_exception()
    {
        return Exception::register_exception(TE, ExceptionT().what());
    }

    virtual const char* what() const throw() override;
};

} // namespace api
} // namespace yogi

#endif // YOGI_API_EXCEPTIONT_HPP
