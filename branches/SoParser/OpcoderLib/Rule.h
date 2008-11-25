#ifndef __SO_RULE_H__
#define __SO_RULE_H__

#include "AutoPtr.h"
#include "RulesVisitor.h"

#include "OpcodePart.h"

namespace SoParse
{
	class IRule;
	typedef SoUtil::AutoPtr<IRule> APIRule;

	class IRulesVisitor;

	class IRule
	{
	public:
		virtual ~IRule() {}

		virtual std::string getName() const = 0;
		virtual char const * getType() const = 0;

		virtual OpcodePart *	getOpcodeStart() = 0;
		virtual OpcodePart *	getOpcodeEnd() = 0;

		virtual APIRule	groupizeAND(APIRule self, APIRule r) = 0;
		virtual APIRule	groupizeOR(APIRule self, APIRule r) = 0;

		virtual void	acceptVisitor(IRulesVisitor * visitor) = 0;
	};

	inline APIRule	operator & (APIRule r1, APIRule r2)
	{
		return r1->groupizeAND(r1, r2);
	}

	inline APIRule	operator | (APIRule r1, APIRule r2)
	{
		return r1->groupizeOR(r1, r2);
	}
}

#endif  // !__SO_RULE_H__
