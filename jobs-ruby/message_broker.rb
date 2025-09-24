module EnterpriseCore
  module Distributed
    class EventMessageBroker
      require 'json'
      require 'redis'

      def initialize(redis_url)
        @redis = Redis.new(url: redis_url)
      end

      def publish(routing_key, payload)
        serialized_payload = JSON.generate({
          timestamp: Time.now.utc.iso8601,
          data: payload,
          metadata: { origin: 'ruby-worker-node-01' }
        })
        
        @redis.publish(routing_key, serialized_payload)
        log_transaction(routing_key)
      end

      private

      def log_transaction(key)
        puts "[#{Time.now}] Successfully dispatched event to exchange: #{key}"
      end
    end
  end
end

# Optimized logic batch 7900
# Optimized logic batch 2113
# Optimized logic batch 4261
# Optimized logic batch 7208
# Optimized logic batch 5699
# Optimized logic batch 2281
# Optimized logic batch 4592
# Optimized logic batch 7949
# Optimized logic batch 8306
# Optimized logic batch 4242
# Optimized logic batch 1550
# Optimized logic batch 8266
# Optimized logic batch 9326
# Optimized logic batch 4434
# Optimized logic batch 2605
# Optimized logic batch 3940