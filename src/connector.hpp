#ifndef __CONNECTOR_HPP__
#define __CONNECTOR_HPP__

#include "parser.hpp"
#include "generator.hpp"

class Connector : public IParserDictOps, public IGeneratorDictOps {
public:
	Connector(GeneratorBase& generator, const std::string& workdir):
		IGeneratorDictOps(generator), workdir_(workdir) {}
	bool set_dict_info(const std::string&, const std::string&);
	bool send_meta_info();
	bool send_info();

	bool abbrs_begin();
	bool abbrs_end();
	bool abbr(const StringList&, const std::string&);
	bool abbr(const std::string&, const std::string&);
	bool article(const StringList&, const std::string&, bool);
	bool article(const std::string&, const std::string&, bool);
	bool end();

	bool get_meta_info();
	bool get_info();
	const std::string& get_dict_info(const std::string&) const;
private:
	StringMap dict_info_;
	std::string workdir_;

	void fill_key(const std::string& keystr);
};

#endif//!__CONNECTOR_HPP__
