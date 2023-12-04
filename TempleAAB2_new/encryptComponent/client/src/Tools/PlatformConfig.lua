FunctionMapping = function(funcKey)
    local resultFunctionName = funcKey
    print("=============resultFunctionName 111:",resultFunctionName)
    if FunctionName and FunctionName[funcKey] and FunctionName[funcKey]~="" then
        resultFunctionName = FunctionName[funcKey]
    end
    print("=============resultFunctionName 222:",resultFunctionName)
    return resultFunctionName
end

FunctionAfLogName = function(funcKey)
    local resultFunctionName = funcKey
    if AfLogEventName and AfLogEventName[funcKey] and AfLogEventName[funcKey]~="" then
        resultFunctionName = AfLogEventName[funcKey]
    end
    return resultFunctionName
end

FunctionADLogName = function(funcKey)
    local resultFunctionName = funcKey
    if ADLogEventName and ADLogEventName[funcKey] and ADLogEventName[funcKey]~="" then
        resultFunctionName = ADLogEventName[funcKey]
    end
    return resultFunctionName
end
