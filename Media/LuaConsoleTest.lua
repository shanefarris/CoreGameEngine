function myprint(...) local str;str = '';for i = 1, arg.n do if str ~= '' then str = str .. '\t' end str = str .. tostring( arg[i] ); end;str = str .. '\n';interpreterOutput( str );end print = myprint

function test()
	print('testing');
end

--function myprint(...)
--	local str
--	str = ''
 
--	for i = 1, arg.n do
--		if str ~= '' then str = str .. '\t' end
--		str = str .. tostring( arg[i] )
--	end
 
--	str = str .. '\n'
 
--	interpreterOutput( str )
--end
 
--oldprint = print
--print = myprint