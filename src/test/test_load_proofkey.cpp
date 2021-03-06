#include <libff/algebra/curves/alt_bn128/alt_bn128_pp.hpp>
#include <libsnark/zk_proof_systems/ppzksnark/r1cs_ppzksnark/r1cs_ppzksnark.hpp>

#include "ZoKrates/wraplibsnark.cpp"


int main( int argc, char **argv )
{
	typedef libff::alt_bn128_pp ppT;

	ppT::init_public_params();

	if( argc < 2 ) {
		std::cerr << "Usage: " << argv[0] << " <proofkey.raw>\n";
		return 1;
	}

	libsnark::r1cs_ppzksnark_proving_key<ppT> pk;

    pk = loadFromFile<decltype(pk)> (argv[1]);

    std::cout << "OK\n";

	return 0;
}